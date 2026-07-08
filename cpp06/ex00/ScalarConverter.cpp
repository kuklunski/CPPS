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
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cctype>
#include <limits>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter() {}

static bool isCharLiteral(const std::string &s)
{
	return (s.size() == 1 && !std::isdigit(static_cast<unsigned char>(s[0])));
}

static bool isPseudoFloat(const std::string &s)
{
	return (s == "-inff" || s == "+inff" || s == "nanf");
}

static bool isPseudoDouble(const std::string &s)
{
	return (s == "-inf" || s == "+inf" || s == "nan");
}

static bool isFloatLiteral(const std::string &s)
{
	if (s.empty() || s[s.size() - 1] != 'f')
		return false;
	std::string sub = s.substr(0, s.size() - 1);
	if (sub.empty())
		return false;
	size_t i = (sub[0] == '-' || sub[0] == '+') ? 1 : 0;
	bool hasDigit = false, hasDot = false;
	for (; i < sub.size(); i++)
	{
		if (std::isdigit(static_cast<unsigned char>(sub[i])))
			hasDigit = true;
		else if (sub[i] == '.' && !hasDot)
			hasDot = true;
		else
			return false;
	}
	return hasDigit;
}

static bool isDoubleLiteral(const std::string &s)
{
	if (s.empty())
		return false;
	size_t i = (s[0] == '-' || s[0] == '+') ? 1 : 0;
	bool hasDigit = false, hasDot = false;
	for (; i < s.size(); i++)
	{
		if (std::isdigit(static_cast<unsigned char>(s[i])))
			hasDigit = true;
		else if (s[i] == '.' && !hasDot)
			hasDot = true;
		else
			return false;
	}
	return hasDigit && hasDot;
}

static bool isIntLiteral(const std::string &s)
{
	if (s.empty())
		return false;
	size_t i = (s[0] == '-' || s[0] == '+') ? 1 : 0;
	if (i >= s.size())
		return false;
	for (; i < s.size(); i++)
	{
		if (!std::isdigit(static_cast<unsigned char>(s[i])))
			return false;
	}
	return true;
}

static void printChar(double value, bool valid)
{
	if (!valid || value != value || std::isinf(value)
		|| value < static_cast<double>(CHAR_MIN)
		|| value > static_cast<double>(CHAR_MAX))
	{
		std::cout << "char: impossible" << std::endl;
		return;
	}
	char c = static_cast<char>(value);
	if (std::isprint(static_cast<unsigned char>(c)))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
}

static void printInt(double value, bool valid)
{
	if (!valid || value != value || std::isinf(value)
		|| value < static_cast<double>(INT_MIN)
		|| value > static_cast<double>(INT_MAX))
	{
		std::cout << "int: impossible" << std::endl;
		return;
	}
	std::cout << "int: " << static_cast<int>(value) << std::endl;
}

static void printFloat(double value, bool valid)
{
	if (!valid)
	{
		std::cout << "float: impossible" << std::endl;
		return;
	}
	if (value != value)
	{
		std::cout << "float: nanf" << std::endl;
		return;
	}
	if (std::isinf(value))
	{
		std::cout << "float: " << (value > 0 ? "+inff" : "-inff") << std::endl;
		return;
	}
	std::ostringstream oss;
	oss << static_cast<float>(value);
	std::string str = oss.str();
	if (str.find('.') == std::string::npos && str.find('e') == std::string::npos) // e for numbers like like 1e+12
		str += ".0";
	std::cout << "float: " << str << "f" << std::endl;
}

static void printDouble(double value, bool valid)
{
	if (!valid)
	{
		std::cout << "double: impossible" << std::endl;
		return;
	}
	if (value != value)
	{
		std::cout << "double: nan" << std::endl;
		return;
	}
	if (std::isinf(value))
	{
		std::cout << "double: " << (value > 0 ? "+inf" : "-inf") << std::endl;
		return;
	}
	std::ostringstream oss;
	oss << value;
	std::string str = oss.str();
	if (str.find('.') == std::string::npos && str.find('e') == std::string::npos)
		str += ".0";
	std::cout << "double: " << str << std::endl;
}

void ScalarConverter::convert(const std::string &literal)
{
	double value = 0;
	bool valid = true;

	if (isCharLiteral(literal))
		value = static_cast<double>(literal[0]);
	else if (isPseudoFloat(literal) || isPseudoDouble(literal))
	{
		if (literal.find("nan") != std::string::npos)
			value = std::numeric_limits<double>::quiet_NaN();
		else if (literal[0] == '-')
			value = -std::numeric_limits<double>::infinity();
		else
			value = std::numeric_limits<double>::infinity();
	}
	else if (isFloatLiteral(literal) || isDoubleLiteral(literal) || isIntLiteral(literal))
		value = std::strtod(literal.c_str(), NULL);
	else
		valid = false;

	printChar(value, valid);
	printInt(value, valid);
	printFloat(value, valid);
	printDouble(value, valid);
}