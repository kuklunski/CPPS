/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 12:41:41 by ylemkere          #+#    #+#             */
/*   Updated: 2026/04/19 12:41:41 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void BitcoinExchange::myInsert(std::string str1, float x)
{
    myMap.insert(std::make_pair(str1, x));
}

void BitcoinExchange::printMap()
{
    std::map<std::string, float>::iterator it;
    int i = 1;
    for (it = myMap.begin(); it != myMap.end(); it++)
        std::cout << "Date: [" << it->first << "] Price: [" << it->second << "]" << " line : " << i++ << std::endl;
}

float BitcoinExchange::getPriceForDate(const std::string& date)
{
    std::map<std::string, float>::iterator it = myMap.lower_bound(date);

    // if exact match
    if (it != myMap.end() && it->first == date)
        return it->second;

    // if we're at begin and no exact match → no earlier date exists
    if (it == myMap.begin())
        return -1;

    // otherwise go to closest lower date
    if (it == myMap.end() || it->first != date)
        --it;

    return it->second;
}