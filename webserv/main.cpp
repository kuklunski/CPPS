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

int create_and_bind_socket(const std::string& host, int port)
{
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd < 0) {
        perror("socket");
        return -1;
    }

    // to not wait until ports are free after every relaunch of the program
    int opt = 1;
    setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    sockaddr_in address;
    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr(host.c_str());
    address.sin_port = htons(port);

    if (bind(fd, reinterpret_cast<sockaddr*>(&address), sizeof(address)) < 0) {
        perror("bind");
        close(fd);
        return -1;
    }

    if (listen(fd, 10) < 0) {
        perror("listen");
        close(fd);
        return -1;
    }

    std::cout << "listening on " << host << ":" << port << std::endl;
    return fd;
}

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


    // declare the vector of pollfd structs and push serverfd into it
    std::vector<struct pollfd> fds;
    std::vector<Client> clients;
    for (size_t i = 0; i < configs.size(); i++)
    {
        int fd = create_and_bind_socket(configs[i].host, configs[i].port);
        if (fd < 0)
            return 1;

        struct pollfd pfd;
        pfd.fd = fd;
        pfd.events = POLLIN;
        fds.push_back(pfd);

        Client c;
        c.fd = fd;
        c.buffer = "";
        c.last_active = 0;
        c.is_server = true;
        clients.push_back(c);
    }
    // poll loop starts here
    int j = 0;
    while (true)
    {
        poll(fds.data(), fds.size(), 5000);

        for (size_t i = 0; i < fds.size(); i++)
        {
            if (clients[i].is_server && fds[i].revents & POLLIN)
            {
                struct sockaddr_in client_addr;
                socklen_t len = sizeof(client_addr);
                int client_fd = accept(fds[i].fd, reinterpret_cast<sockaddr*>(&client_addr), &len);
                if (client_fd < 0) {
                    perror("accept");
                    continue;
                }
                struct pollfd client_pollfd;
                client_pollfd.fd = client_fd;
                client_pollfd.events = POLLIN;
                fds.push_back(client_pollfd);

                Client c;
                c.fd = client_fd;
                c.buffer = "";
                c.last_active = time(NULL);
                c.is_server = false;
                clients.push_back(c);
            }
            else if (fds[i].revents & POLLIN)
            {
                char buffer[1024];
                ssize_t recv_bytes = recv(fds[i].fd, buffer, sizeof(buffer), 0);
                if (recv_bytes > 0)
                {
                    ++j;
                    clients[i].buffer.append(buffer, recv_bytes);
                    clients[i].last_active = time(NULL);
                    if (clients[i].buffer.find("\r\n\r\n") != std::string::npos)
                    {
                        std::cout << "request completed " << j << std::endl;
                        std::string response =  "HTTP/1.1 200 OK\r\n"
                                                "Content-Length: 5\r\n"
                                                "\r\n"
                                                "Hello";
                        ssize_t total_sent = 0;
                        size_t response_len = response.size();
                        while (total_sent < (ssize_t)response_len)
                        {
                            ssize_t sent = send(fds[i].fd, response.c_str() + total_sent, response_len - total_sent, 0);
                            if (sent <= 0)
                                break;
                            total_sent += sent;
                        }
                        close(fds[i].fd);
                        fds.erase(fds.begin() + i);
                        clients.erase(clients.begin() + i);
                        i--;
                    }
                }
                else if (recv_bytes == 0)
                {
                    std::cout << "client disconnected" << std::endl;
                    close(fds[i].fd);
                    fds.erase(fds.begin() + i);
                    clients.erase(clients.begin() + i);
                    i--;
                }
                else
                {
                    std::cerr << "Error in recv" << std::endl;
                    close(fds[i].fd);
                    fds.erase(fds.begin() + i);
                    clients.erase(clients.begin() + i);
                    i--;
                }
            }
            else if (fds[i].revents & POLLHUP)
            {
                close(fds[i].fd);
                fds.erase(fds.begin() + i);
                clients.erase(clients.begin() + i);
                i--;
            }
        }

        // timeout check
        time_t now = time(NULL);
        for (size_t i = 0; i < clients.size(); i++)
        {
            if (clients[i].is_server)
                continue;
            if (now - clients[i].last_active > 30)
            {
                std::cout << "client timed out: " << clients[i].fd << std::endl;
                close(clients[i].fd);
                fds.erase(fds.begin() + i);
                clients.erase(clients.begin() + i);
                i--;
            }
        }
    }
    return 0;
}