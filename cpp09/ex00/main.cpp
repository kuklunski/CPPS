/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 03:16:36 by ylemkere          #+#    #+#             */
/*   Updated: 2026/04/18 03:16:36 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main (int ac, char* av[])
{
    BitcoinExchange btc;
    std::string buff;

    //initial checks
    if (ac != 2)
    {
        std::cerr << "error in arguments !" << std::endl;
        return 1;
    }

    // Opening the file
    std::ifstream file("data.csv");
    if (!file)
    {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    // filling the database map
    float btcPrice;
    while (std::getline(file, buff))
    {
        std::stringstream ss(buff);
        std::string date;
        std::string price;
        
        if (std::getline(ss, date, ','))
        {
            if (std::getline(ss, price))
            {
                //std::cout << "Date: [" << date << "] Price: [" << price << "]" << " line : " << i << std::endl;
                std::stringstream ssp(price);
                ssp >> btcPrice;
                //std::cout << btcPrice << std::endl;
                btc.myInsert(date, btcPrice);
            }
        }
    }
    // btc.printMap();

    // opening the input file
    std::ifstream inputfile(av[1]);
    if (!inputfile)
    {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    // verify file is not empty
    std::string inputbuff;
    if (!std::getline(inputfile, inputbuff))
    {
        std::cout << "Error : wrong input" << std::endl;
        return 1;
    }

    // verify first line
    if (inputbuff != "date | value")
    {
        std::cout << "Error : wrong input" << std::endl;
        return 1;
    }
    // checking input than compare with btc prices map
    while (std::getline(inputfile, inputbuff))
    {
        std::stringstream ssi(inputbuff);
        std::string firsthalf;
        std::string secondhalf;
        std::string year;
        std::string month;
        std::string day;
        float quantity;
        // checking for empty lines
        if (inputbuff.find_first_not_of(" \t\n\r") == std::string::npos) // npos is like the string version of NULL
        {
            //std::cout << "empty line or full of spaces at : " << i << std::endl;
            continue;
        }
        // checking for lines containing only separators
        if (inputbuff.find_first_not_of("|-") == std::string::npos) // npos is like the string version of NULL
        {
            std::cout << "Error : wrong input (no data)" << std::endl;
            continue;
        }

        // checking for lines with only the quantity "| 5"
        if (!std::getline(ssi, firsthalf, '|'))
        {
            std::cout << "Error : wrong input (date)" << std::endl;
            continue;
        }

        // checking for lines with only the date "year-month-day |"
        //std::cout << firsthalf << std::endl;
        if (!std::getline(ssi, secondhalf))
        {
            std::cout << "Error : wrong input (quantity)" << std::endl;
            continue;
        }

        //checking that quantity is in fact a number and valid and no extras after it
        //std::cout << firsthalf << std::endl;
        std::stringstream ssquantity(secondhalf);
        std::string extra;
        if (!(ssquantity >> quantity) || (ssquantity >> extra))
        {
            std::cout << "Error : wrong input (quantity)" << std::endl;
            continue;
        }
        if (quantity > 1000 || quantity < 0)
        {
            std::cout << "invalid number : number out of bounds" << std::endl;
            continue;
        }

        // processing "year-month-day |"
        std::stringstream ssii(firsthalf);

        //extracting the year value and validating it at the same time
        if (!std::getline(ssii, year, '-'))
        {
            std::cout << "Error : wrong input (year)" << std::endl;
            continue;
        }
        if (year.size() != 4)
        {
           std::cout << "Error : wrong input (year)" << std::endl;
            continue; 
        }
        std::stringstream ssyear(year);
        //std::cout << year << std::endl;
        std::string yearextra;
        int fyear;
        if (!(ssyear >> fyear) || (ssyear >> yearextra) || fyear > 2999 || fyear < 0)
        {
            std::cout << "Error : wrong input (year)" << std::endl;
            continue;
        }
        
        // processing the second field of "xxxx-month-xx"
        if (!std::getline(ssii, month, '-'))
        {
            std::cout << "Error : wrong input (month)" << std::endl;
            continue;
        }
        if (month.size() != 2)
        {
            std::cout << "Error : wrong input (month)" << std::endl;
            continue; 
        }
        std::stringstream ssmonth(month);
        //std::cout << year << std::endl;
        std::string monthextra;
        int fmonth;
        if (!(ssmonth >> fmonth) || (ssmonth >> monthextra) || fmonth > 12 || fmonth < 1)
        {
            std::cout << "Error : wrong input (month)" << std::endl;
            continue;
        }

        // processing the second field of "xxxx-xx-day"
        if (!std::getline(ssii, day, '|') || day.length() != 3)
        {
            std::cout << "Error : wrong input (day)" << std::endl;
            continue;
        }
        //std::cout << day << "." << std::endl;
        std::stringstream ssday(day);
        std::string dayextra;
        int fday;
        if (!(ssday >> fday) || (ssday >> dayextra) || fday > 31 || fday < 1)
        {
            std::cout << "Error : wrong input (day)" << std::endl;
            continue;
        }
        // remove a trailing space
        firsthalf.erase(firsthalf.size() - 1);
        
        // if (btc.myMap.find(firsthalf) != btc.myMap.end())
        // {
        //     std::cout << "first half : " << firsthalf  << "."<< std::endl;
        //     std::cout << "found\n";
        // }
        float price = btc.getPriceForDate(firsthalf);
        if (price != -1)
        {
            std::cout << firsthalf << " => ";
            std::cout.unsetf(std::ios::floatfield);
            std::cout << std::setprecision(6) << quantity << " = ";
            std::cout << std::fixed << std::setprecision(2)
            << price * quantity
            << std::endl;
            std::cout.unsetf(std::ios::floatfield);
            std::cout << std::setprecision(6);
        }
    }
    // debugg
    // std::string buff;
    // int i = 0;
    // while (std::getline(file, buff) && i++ < 10)
    // {
    //     std::cout << buff << std::endl;
    // }

    return 0;
}