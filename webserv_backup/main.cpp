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

#include "part_C.hpp"
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
                c.fd          = client_fd;
                c.send_queue  = "";
                c.last_active = time(NULL);
                c.is_server   = false;
                c.server_port = configs[i].port;
                c.server_name = configs[i].server_name;
                c.remote_addr = inet_ntoa(client_addr.sin_addr);
                c.All         = new all();
                clients.push_back(c);
            }
            else if (fds[i].revents & POLLIN)
            {
                char buffer[4096];
                ssize_t recv_bytes = recv(fds[i].fd, buffer, sizeof(buffer), 0);

                if (recv_bytes > 0)
                {
                    clients[i].last_active = time(NULL);
                    all* a = clients[i].All;

                    if (!a->headers_done)
                    {
                        a->req.raw_request.append(buffer, recv_bytes);

                        size_t header_end = a->req.raw_request.find("\r\n\r\n");
                        if (header_end != std::string::npos)
                        {
                            a->headers_done = true;

                            // bytes that arrived after \r\n\r\n in this same recv are body data
                            std::string overflow = a->req.raw_request.substr(header_end + 4);
                            a->req.raw_request.erase(header_end + 4); // keep headers + \r\n\r\n only

                            // TODO: replace with B's real header parser
                            // a->req.content_length = get_content_length(a->req.raw_request);
                            a->req.content_length = 0; // stub until B exposes the real function

                            if (a->req.content_length > 0)
                            {
                                std::ostringstream oss;
                                oss << "/tmp/webserv_body_" << clients[i].fd;
                                a->req.body_filepath = oss.str();
                                a->req.body_fd = open(a->req.body_filepath.c_str(),
                                                    O_CREAT | O_WRONLY | O_TRUNC, 0644);

                                if (a->req.body_fd < 0)
                                {
                                    perror("open");
                                    // TODO: send 500, cleanup client
                                }

                                if (!overflow.empty())
                                {
                                    write(a->req.body_fd, overflow.c_str(), overflow.size());
                                    a->body_bytes_written += overflow.size();
                                }

                                if (a->body_bytes_written >= a->req.content_length)
                                {
                                    close(a->req.body_fd);
                                    std::cout << "request complete (with body)" << std::endl;
                                    // TODO: reader(*a, fds[i].fd);
                                    // TODO: clients[i].send_queue = a->res.respond;
                                    // TODO: fds[i].events = POLLIN | POLLOUT;
                                }
                            }
                            else
                            {
                                // no body expected (GET, DELETE, or POST with no Content-Length)
                                std::cout << "request complete (no body)" << std::endl;
                                // TODO: reader(*a, fds[i].fd);
                                // TODO: clients[i].send_queue = a->res.respond;
                                // TODO: fds[i].events = POLLIN | POLLOUT;
                            }
                        }
                    }
                    else
                    {
                        // headers already parsed, this recv is pure body bytes
                        write(a->req.body_fd, buffer, recv_bytes);
                        a->body_bytes_written += recv_bytes;

                        if (a->body_bytes_written >= a->req.content_length)
                        {
                            close(a->req.body_fd);
                            std::cout << "request complete (body finished)" << std::endl;
                            // TODO: reader(*a, fds[i].fd);
                            // TODO: clients[i].send_queue = a->res.respond;
                            // TODO: fds[i].events = POLLIN | POLLOUT;
                        }
                    }
                }
                else if (recv_bytes == 0)
                {
                    std::cout << "client disconnected" << std::endl;
                    if (clients[i].All->req.body_fd >= 0)
                        close(clients[i].All->req.body_fd);
                    delete clients[i].All;
                    close(fds[i].fd);
                    fds.erase(fds.begin() + i);
                    clients.erase(clients.begin() + i);
                    i--;
                }
                else
                {
                    std::cerr << "Error in recv" << std::endl;
                    if (clients[i].All->req.body_fd >= 0)
                        close(clients[i].All->req.body_fd);
                    delete clients[i].All;
                    close(fds[i].fd);
                    fds.erase(fds.begin() + i);
                    clients.erase(clients.begin() + i);
                    i--;
                }
            }
            else if (fds[i].revents & POLLOUT)
            {
                // TODO: uncomment when C is ready
                // ssize_t sent = send(fds[i].fd,
                //                     clients[i].send_queue.c_str(),
                //                     clients[i].send_queue.size(), 0);
                // if (sent > 0)
                // {
                //     clients[i].send_queue.erase(0, sent);
                //     if (clients[i].send_queue.empty())
                //     {
                //         delete clients[i].All;
                //         clients[i].All = NULL;
                //         close(fds[i].fd);
                //         fds.erase(fds.begin() + i);
                //         clients.erase(clients.begin() + i);
                //         i--;
                //     }
                // }
                // else
                // {
                //     delete clients[i].All;
                //     close(fds[i].fd);
                //     fds.erase(fds.begin() + i);
                //     clients.erase(clients.begin() + i);
                //     i--;
                // }
            }
            else if (fds[i].revents & POLLHUP)
            {
                delete clients[i].All;
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
                delete clients[i].All;
                close(clients[i].fd);
                fds.erase(fds.begin() + i);
                clients.erase(clients.begin() + i);
                i--;
            }
        }
    }
    return 0;
}