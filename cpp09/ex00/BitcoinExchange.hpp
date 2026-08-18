/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 12:41:38 by ylemkere          #+#    #+#             */
/*   Updated: 2026/04/19 12:41:38 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <map>
#include <iomanip>

class BitcoinExchange
{
    private :
        std::map<std::string, float> myMap;
    public :
        void myInsert(std::string str1, float x);
        void printMap();
        float getPriceForDate(const std::string& date);
};

#endif
