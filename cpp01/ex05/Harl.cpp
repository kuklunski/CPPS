/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 00:05:05 by ylemkere          #+#    #+#             */
/*   Updated: 2025/12/09 00:05:05 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void Harl::debug( void )
{
    std::cout << "Debugggg !!!" << std::endl;
}
void Harl::info( void )
{
    std::cout << "infoo !!!" << std::endl;
}
void Harl::warning( void )
{
    std::cout << "warningggg !!!" << std::endl;
}
void Harl::error( void )
{
    std::cout << "Errooooor !!!" << std::endl;
}

void Harl::complain( std::string level )
{
    Harl harley;
    void (Harl::*ptrToMemberFunc_array[])(void) = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };
    int i = 0;
    while (level == "DEBUG" && i < 1)
    {
        (harley.*ptrToMemberFunc_array[0])();
        i++;
    }
    while (level == "INFO" && i < 1)
    {
        (harley.*ptrToMemberFunc_array[1])();
        i++;
    }
    while (level == "WARNING" && i < 1)
    {
        (harley.*ptrToMemberFunc_array[2])();
        i++;
    }
    while (level == "ERROR" && i < 1)
    {
        (harley.*ptrToMemberFunc_array[3])();
        i++;
    }
}