/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 21:41:51 by ylemkere          #+#    #+#             */
/*   Updated: 2026/02/27 21:41:51 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>

class ScalarConverter
{
    public :
        //static void convert(std::string &str);
        ScalarConverter();
        ScalarConverter(const ScalarConverter &);
        ScalarConverter& operator=(const ScalarConverter &);
        ~ScalarConverter();
};

#endif