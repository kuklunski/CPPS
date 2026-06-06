/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 21:41:49 by ylemkere          #+#    #+#             */
/*   Updated: 2026/02/27 21:41:49 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// static void convert(std::string &str)
// {
//     std::cout << "char: " << static_cast<char>str << std::endl;
//     std::cout << "int: " << static_cast<int>str << std::endl;
//     std::cout << "float: " << static_cast<float>str << std::endl;
//     std::cout << "double: " << static_cast<double>str << std::endl;
// }

ScalarConverter::ScalarConverter()
{
    std::cout << "SC default constructor\n";
}

ScalarConverter::ScalarConverter(const ScalarConverter &)
{
    std::cout << "SC copy constructor\n";
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &)
{
    std::cout << "SC copy assignment operator\n";
    return *this;
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "SC destructor\n";
}