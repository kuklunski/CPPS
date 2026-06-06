/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 03:04:37 by ylemkere          #+#    #+#             */
/*   Updated: 2025/11/21 03:04:37 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int main (void)
{
    Phonebook instance_phonebook;
    std::string Cup;

    while (Cup != "EXIT")
    {
        std::cout << "* Available commands : ADD, SEARCH, EXIT" << std::endl;
        if (!std::getline(std::cin, Cup))
            break;
        if (Cup == "ADD")
            instance_phonebook.add();
        else if (Cup == "SEARCH")
            instance_phonebook.search();
        else if (Cup == "EXIT")
            break;
    }
    return (0);
}