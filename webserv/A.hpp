/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 00:33:24 by ylemkere          #+#    #+#             */
/*   Updated: 2026/06/23 00:33:24 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h> // bind() sockaddr_in
#include <cstring>
#include <unistd.h>
#include <vector>
#include <poll.h>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <arpa/inet.h>

// ─── Structs ────────────────────────────────────────────────────────────────

struct LocationConfig
{
    std::string              path;
    std::string              root;
    std::string              index;
    std::vector<std::string> methods;
    bool                     autoindex;
    std::string              upload_store;
    std::string              cgi_ext;
    std::string              redirect;
    int                      max_body;

    LocationConfig() : autoindex(false), max_body(0) {}
};

struct ServerConfig
{
    std::string                 host;
    int                         port;
    std::string                 server_name;
    std::string                 root;
    std::string                 index;
    std::map<int, std::string>  error_pages;
    int                         max_body;
    std::vector<LocationConfig> locations;

    ServerConfig() : port(0), max_body(0) {}
};

struct Client {
    int         fd;
    std::string buffer;
    time_t      last_active;
    bool        is_server;
};

void print_configs(const std::vector<ServerConfig>& configs);
std::vector<ServerConfig> parse_config(const std::string& filename);
ServerConfig parse_server(std::ifstream& file);
LocationConfig parse_location(std::ifstream& file, const std::string& path);
std::vector<std::string> tokenize(const std::string& line);