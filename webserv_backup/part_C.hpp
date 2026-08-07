#ifndef PART_C_HPP
#define PART_C_HPP

#include <string>
#include <sys/stat.h>
#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <sys/wait.h>
#include <vector>

const long long MAX_SIZE = 168435456;

class request
{
    public:
        std::string raw_request;
        std::string method;
        std::string URLpath;
        std::string reqbody;
        int         isCGI;
        //
        std::string queryString;
        std::string contentType;
        std::string serverProtocol;
        std::string scriptName;
        std::string pathInfo;
        std::string remoteAddr;
        std::string serverName;
        std::string serverPort;
        std::string Redirect_Status;

        // new
        std::string body_filepath;
        int         body_fd;
        size_t      content_length;

        request() : isCGI(0), body_fd(-1), content_length(0) {}
};

class configpath
{
    public:
        std::string servPath;
        std::string fullPath;
        std::string indexPath;
        std::string redPath;
};

class respond
{
    public:
        std::string body;
        int         status;
        std::string statusText;
        std::string contentType;
        size_t      contentLenght;
        std::string respond;
        std::string location;
        std::string respondHeaders;
};

class indx
{
    public:
        std::string indxfl;
        int         utoindx;

};

class all
{
    public:
        request                     req;
        configpath                  conp;
        respond                     res;
        indx                        idx;
        size_t                      size;
        size_t                      rbyte;
        int                         stdinPipe[2];
        int                         stdoutPipe[2];
        char                        **envi;
        std::vector<std::string>    CGIenv;
        std::vector<char *>         CGIenvp;
        std::string                 compiler;
        // new
        bool                        headers_done;
        size_t                      body_bytes_written;

        all() : headers_done(false), body_bytes_written(0) {}
};

//don't forget index path separet than full index in file readerr.cpp function directory_handler!!
void        error_handler(int er, all &al, int fd);
int         reader(all &al, int fd);
void        directory_handler(all &al);
int         open_read_file(all &al, struct stat &st, std::string &path);
int         handle_auto_index(all &al);
void        make_respond(all &al);
std::string get_content_type(const std::string &fille);
void        delet_method(all &al);
void        post_method(all &al);
int         check_if_allowed(all &al);
void        redirect_method(all &al);
void        CGIhandler(all &al);
int         check_CGI_header(std::string headers);
void        parse_CGI_output(all &al);
void        make_CGI_env(all &al);
int         get_CGI_compiler(all &al);

#endif