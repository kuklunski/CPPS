/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 22:41:49 by ylemkere          #+#    #+#             */
/*   Updated: 2026/06/22 22:41:49 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
// AF_INET      // IPv4
// AF_INET6     // IPv6
// AF_UNIX      // Local IPC
// SOCK_STREAM  // TCP
// SOCK_DGRAM   // UDP
// SOCK_RAW     // Raw packets
// Usually 0 to let the OS choose the default protocol.
// 0  // TCP for SOCK_STREAM
// returns >= 0 on success
// -1 on failure
int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./parser <config_file>" << std::endl;
        return 1;
    }

    std::vector<ServerConfig> configs = parse_config(argv[1]);

    if (configs.empty())
    {
        std::cerr << "No server blocks found or file empty" << std::endl;
        return 1;
    }

    print_configs(configs);
    //return 0;
    // socket creation
    int serverfd = socket(AF_INET, SOCK_STREAM, 0);
    if (serverfd < 0) { 
        std::cerr << "Error in socket" << std::endl;
        return 1;
    }
    std::cout << "socket created : " << serverfd << std::endl;

    // everytime i rerun the program, It holds me in a TIME_WAIT state 
    //  for ~60 seconds to catch any late packets still traveling through the network
    // SO_REUSEADDR tells the OS "let me reclaim this port even if it's in TIME_WAIT."
    int opt = 1;
    setsockopt(serverfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    // bind()
    sockaddr_in address;
    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);
    int bind_return = bind(serverfd, reinterpret_cast<sockaddr*>(&address), sizeof(address));
    if (bind_return < 0) {
        perror("bind");
        std::cerr << "Error in bind" << std::endl;
        return 1;
    }
    std::cout << "bind completed : " << bind_return << std::endl;

    // listen()
    int listen_ret = listen(serverfd, SOMAXCONN);
    if (listen_ret < 0) {
        std::cerr << "Error in listen : " << listen_ret << std::endl;
        return 1;
    }
    std::cout << "listening !" << std::endl;

    // declare the vector of pollfd structs and push serverfd into it
    std::vector<struct pollfd> fds;
    struct pollfd server_pollfd;
    server_pollfd.fd = serverfd;
    server_pollfd.events = POLLIN;
    fds.push_back(server_pollfd);
    std::vector<std::string> buffers;
    buffers.push_back("");
    // we push one buffer so that clients fd and buffer both start at index = 1
    int j = 0;
    while (true)
    {
        poll(fds.data(), fds.size(), 5000);
        for (size_t i = 0; i < fds.size(); i++)
        {
            if (fds[i].fd == serverfd && fds[i].revents & POLLIN)
            {
                struct sockaddr_in client_addr;
                socklen_t len = sizeof(client_addr);
                int client_fd = accept(serverfd, reinterpret_cast<sockaddr*>(&client_addr), &len);
                if (client_fd < 0) {
                    perror("accept");
                    continue;
                }
                struct pollfd client_pollfd;
                client_pollfd.fd = client_fd;
                client_pollfd.events = POLLIN;
                fds.push_back(client_pollfd);
                buffers.push_back("");
            }
            else if (fds[i].revents & POLLIN)
            {
                // recv
                char buffer[1024];
                ssize_t recv_bytes = recv(fds[i].fd, buffer, sizeof(buffer), 0);
                if (recv_bytes > 0)
                {
                    ++j;
                    buffers[i].append(buffer, recv_bytes);
                    if (buffers[i].find("\r\n\r\n") != std::string::npos)
                    {
                        std::cout << "request completed" << j << std::endl;
                        //send as before
                        std::string response =  "HTTP/1.1 200 OK\r\n"
                                                "Content-Length: 5\r\n"
                                                "\r\n"
                                                "Hello";
                        ssize_t total_sent = 0;
                        size_t response_len = response.size();
                        // we cast so that we compare ssize_t(total_sent) with ssize_t(len)
                        while (total_sent < (ssize_t)response_len)
                        {
                            // handle partial sends, we move the buffer by what was send response.c_str() + total_sent
                            // and then we calculate the length of length of the message - what was sent
                            ssize_t sent = send(fds[i].fd, response.c_str() + total_sent, response_len - total_sent, 0);
                        
                            if (sent <= 0)
                                break;
                            total_sent += sent;
                        }
                        close(fds[i].fd);
                        buffers.erase(buffers.begin() + i);
                        fds.erase(fds.begin() + i);
                        i--;
                    }
                }
                else if (recv_bytes == 0)
                {
                    std::cout << "client disconnected " << std::endl;
                    close(fds[i].fd);
                    buffers.erase(buffers.begin() + i);
                    fds.erase(fds.begin() + i);
                    i--;
                }
                else{
                        std::cerr << "Error in recv" << std::endl;
                        close(fds[i].fd);
                        buffers.erase(buffers.begin() + i);
                        fds.erase(fds.begin() + i);
                        i--;
                }
            }
            else if (fds[i].revents & POLLHUP)
            {
                // client disconnected
                close(fds[i].fd);
                buffers.erase(buffers.begin() + i);
                fds.erase(fds.begin() + i);
                i--;
            }
        }
    }
    close(serverfd);
    // while (true)
    // {
    //     // accept()
    //     struct sockaddr_in client_addr;
    //     socklen_t len = sizeof(client_addr);
    //     int client_fd = accept(serverfd, reinterpret_cast<sockaddr*>(&client_addr), &len);
    //     if (client_fd < 0) {
    //         std::cerr << "Error on accept : " << client_fd << std::endl;
    //         return 1;
    //     }
    //     std::cout << "accept completed : " << client_fd << std::endl;

    //     //recv to start receiving bytes
    //     char buffer[1024];
    //     std::string raw_request;
    //     //ssize_t bytes = recv(client_fd, buffer, sizeof(buffer), 0);
    //     while (true)
    //     {
    //         // receive the bytes
    //         ssize_t recv_bytes = recv(client_fd, buffer, sizeof(buffer), 0);
    //         if (recv_bytes > 0)
    //         {
    //             raw_request.append(buffer, recv_bytes);
    //             if (raw_request.find("\r\n\r\n") != std::string::npos)
    //             {
    //                 std::cout << "request complete" << std::endl;
    //                 break;
    //             }
    //         }
    //         else if( recv_bytes == 0)
    //         {
    //             std::cout << "client disconnected " << std::endl;
    //             close(client_fd);
    //             break ;
    //         }
    //         else
    //         {
    //             std::cerr << "Error in recv" << std::endl;
    //             close(client_fd);
    //             break ;
    //         }

    //     }
    //     // send back the response
    //     std::string response =  "HTTP/1.1 200 OK\r\n"
    //                             "Content-Length: 5\r\n"
    //                             "\r\n"
    //                             "Hello";
    //     ssize_t total_sent = 0;
    //     size_t response_len = response.size();
    //     // we cast so that we compare ssize_t(total_sent) with ssize_t(len)
    //     while (total_sent < (ssize_t)response_len)
    //     {
    //         // handle partial sends, we move the buffer by what was send response.c_str() + total_sent
    //         // and then we calculate the length of length of the message - what was sent
    //         ssize_t sent = send(client_fd, response.c_str() + total_sent, response_len - total_sent, 0);
        
    //         if (sent <= 0)
    //             break;
    //         total_sent += sent;
    //     }
    //     close(client_fd);
    // }
    return 0;
}