/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 02:08:53 by ylemkere          #+#    #+#             */
/*   Updated: 2025/12/09 02:08:53 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

std::string make_output_file(std::string filename)
{
    std::string result = "";
    if (filename.empty() || filename == "." || filename == "..") {
        std::cout << "Error in Filename." << std::endl;
        return result;
    }
    result = filename + ".replace";
    std::cout << result << std::endl;
    return result;
}

int main(int ac, char **argv) 
{
    if (ac == 4)
    {
        int i = 1;
        if (std::string(argv[1]).empty() || std::string(argv[2]).empty())
        {
            std::cout << "do not play games with me !!" << std::endl;
            return 0;
        }
            
        std::ifstream inputFile(argv[1]);
        std::string output_file = make_output_file(argv[1]);
        if (output_file == "")
            return (0);

        std::ofstream outputFile(output_file.c_str());

        if (!inputFile.is_open() || !outputFile.is_open()) {
            std::cerr << "Error opening file!" << std::endl;
            return 1;
        }

        std::string line;
        while (std::getline(inputFile, line)) 
        {
            size_t pos = line.find(argv[2]);
            std::string argv2 = argv[2];
            std::string argv3 = argv[3];
            while (pos != std::string::npos)
            {
                line.insert(pos, argv[3]);
                //std::cout << "found: "<< argv[2] << " => at line:"<< i << std::endl;
                line.erase(pos + argv3.length(), argv2.length());
                pos = line.find(argv[2], pos + argv3.length());
            }
            outputFile << line << "\n";
            i++;
        }
        outputFile << std::endl;

        inputFile.close();
        outputFile.close(); 
    }
    return 0;
}