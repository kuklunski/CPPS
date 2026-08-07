#include "A.hpp"

// ─── Helpers ────────────────────────────────────────────────────────────────

std::vector<std::string> tokenize(const std::string& line)
{
    std::vector<std::string> tokens;
    std::istringstream ss(line);
    std::string token;
    while (ss >> token)
    {
        // some config files have ; trailing, and some not
        if (!token.empty() && token[token.size() - 1] == ';')
            token = token.substr(0, token.size() - 1);
        // skip comments
        if (token[0] == '#')
            break;
        tokens.push_back(token);
    }
    return tokens;
}

// ─── Parsers ────────────────────────────────────────────────────────────────

LocationConfig parse_location(std::ifstream& file, const std::string& path)
{
    LocationConfig loc;
    loc.path = path;
    std::string line;

    while (std::getline(file, line))
    {
        std::vector<std::string> tokens = tokenize(line);
        if (tokens.empty())
            continue;
        if (tokens[0] == "}")
            break;

        if (tokens[0] == "methods" || tokens[0] == "allow_methods")
        {
            for (size_t i = 1; i < tokens.size(); i++)
                loc.methods.push_back(tokens[i]);
        }
        else if (tokens[0] == "root")
            loc.root = tokens[1];
        else if (tokens[0] == "index")
            loc.index = tokens[1];
        else if (tokens[0] == "autoindex")
            loc.autoindex = (tokens[1] == "on");
        else if (tokens[0] == "upload_store")
            loc.upload_store = tokens[1];
        else if (tokens[0] == "cgi_ext")
            loc.cgi_ext = tokens[1];
        else if (tokens[0] == "redirect")
            loc.redirect = tokens[1];
        else if (tokens[0] == "client_max_body_size")
            loc.max_body = atoi(tokens[1].c_str());
    }
    return loc;
}

ServerConfig parse_server(std::ifstream& file)
{
    ServerConfig config;
    std::string line;

    while (std::getline(file, line))
    {
        std::vector<std::string> tokens = tokenize(line);
        if (tokens.empty())
            continue;
        if (tokens[0] == "}")
            break;
        if (tokens[0] == "listen")
            config.port = atoi(tokens[1].c_str());
        else if (tokens[0] == "root")
            config.root = tokens[1];
        else if (tokens[0] == "index")
            config.index = tokens[1];
        else if (tokens[0] == "server_name")
            config.server_name = tokens[1];
        if (tokens[0] == "host")
            config.host = tokens[1];
        else if (tokens[0] == "port")
            config.port = atoi(tokens[1].c_str());
        else if (tokens[0] == "error_page")
        {
            int code = atoi(tokens[1].c_str());
            config.error_pages[code] = tokens[2];
        }
        else if (tokens[0] == "client_max_body_size")
            config.max_body = atoi(tokens[1].c_str());
        else if (tokens[0] == "location")
            config.locations.push_back(parse_location(file, tokens[1]));
    }
    return config;
}

std::vector<ServerConfig> parse_config(const std::string& filename)
{
    std::vector<ServerConfig> configs;
    std::ifstream file(filename.c_str());

    if (!file.is_open())
    {
        std::cerr << "Error: cannot open config file: " << filename << std::endl;
        return configs;
    }

    std::string line;
    while (std::getline(file, line))
    {
        std::vector<std::string> tokens = tokenize(line);
        if (tokens.empty())
            continue;
        if (tokens[0] == "server")
            configs.push_back(parse_server(file));
    }
    return configs;
}

// ─── Print helper ───────────────────────────────────────────────────────────

void print_configs(const std::vector<ServerConfig>& configs)
{
    for (size_t i = 0; i < configs.size(); i++)
    {
        std::cout << "=== SERVER " << i << " ===" << std::endl;
        std::cout << "  host        : " << configs[i].host << std::endl;
        std::cout << "  port        : " << configs[i].port << std::endl;
        std::cout << "  server_name : " << configs[i].server_name << std::endl;
        std::cout << "  root        : " << configs[i].root << std::endl;
        std::cout << "  index       : " << configs[i].index << std::endl;
        std::cout << "  max_body    : " << configs[i].max_body << std::endl;

        std::map<int, std::string>::const_iterator it;
        for (it = configs[i].error_pages.begin(); it != configs[i].error_pages.end(); it++)
            std::cout << "  error       : " << it->first << " -> " << it->second << std::endl;

        for (size_t j = 0; j < configs[i].locations.size(); j++)
        {
            const LocationConfig& loc = configs[i].locations[j];
            std::cout << "  --- location " << loc.path << " ---" << std::endl;
            std::cout << "    root         : " << loc.root << std::endl;
            std::cout << "    index        : " << loc.index << std::endl;
            std::cout << "    autoindex    : " << (loc.autoindex ? "on" : "off") << std::endl;
            std::cout << "    upload_store : " << loc.upload_store << std::endl;
            std::cout << "    cgi_ext      : " << loc.cgi_ext << std::endl;
            std::cout << "    redirect     : " << loc.redirect << std::endl;
            std::cout << "    max_body     : " << loc.max_body << std::endl;
            std::cout << "    methods      : ";
            for (size_t k = 0; k < loc.methods.size(); k++)
                std::cout << loc.methods[k] << " ";
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}

// ─── Main ───────────────────────────────────────────────────────────────────

// int main(int argc, char* argv[])
// {
//     if (argc != 2)
//     {
//         std::cerr << "Usage: ./parser <config_file>" << std::endl;
//         return 1;
//     }

//     std::vector<ServerConfig> configs = parse_config(argv[1]);

//     if (configs.empty())
//     {
//         std::cerr << "No server blocks found or file empty" << std::endl;
//         return 1;
//     }

//     print_configs(configs);
//     return 0;
// }

// std::string removeSpaces(std::string line)
// {
//     std::string result = "";
//     for (size_t i = 0; i < line.length(); ++i) {
//         if (!::isspace(static_cast<unsigned char>(line[i]))) {
//             result += line[i];
//         }
//     }
//     return result;
// }

// int main (int ac, char* av[])
// {
//     if (ac != 2) {
//         std::cout << "Wrong number of args !" << std::endl;
//         return 1;
//     }

//     std::ifstream configFile(av[1]);
//     if (!configFile.is_open()) {
//         std::cerr << "Error: Could not open the file!" << std::endl;
//         return 1;
//     }

//     std::string line;
//     std::string noSpaces;
//     while (std::getline(configFile, line)) {
//         noSpaces = removeSpaces(line);
//         if (noSpaces == "server{") {
//             std::cout << "found a server block" << std::endl;
//             std::cout << line << std::endl;
//         }
//     }
//     return 0;
// }