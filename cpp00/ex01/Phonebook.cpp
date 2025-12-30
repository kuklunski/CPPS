/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 22:30:23 by ylemkere          #+#    #+#             */
/*   Updated: 2025/11/25 22:30:23 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include "Contact.hpp"

Phonebook::Phonebook(void)
{
    this->index = 0;
    std::cout << "*Phonebook Program Started :" << std::endl;
}

Phonebook::~Phonebook(void)
{
    std::cout << "*Phonebook Program ended ." << std::endl;
}

void    Phonebook::add(void)
{
    std::string cup;

    cup = "";
    while (cup == "")
    {
        std::cout << "*Please enter the contact's First name :" << std::endl;
        std::getline(std::cin, cup);
        if (cup != "")
        {
            this->contacts[this->index % 8].set_fname(cup);
            std::cout <<"+ First name added" << std::endl;
        }
    }
    cup = "";
    while (cup == "")
    {
        std::cout << "*Please enter their Last name :" << std::endl;
        std::getline(std::cin, cup);
        if (cup != "")
        {
            this->contacts[this->index % 8].set_lname(cup);
            std::cout << "+ Last name added" << std::endl;
        }
    }
    cup = "";
    while (cup == "")
    {
        std::cout << "*Please enter their Nickname :" << std::endl;
        std::getline(std::cin, cup);
        if (cup != "")
        {
            this->contacts[this->index % 8].set_nickname(cup);
            std::cout <<"+ Nickname added "<< std::endl;
        }
    }
    cup = "";
    while (cup == "")
    {
        std::cout << "*Please enter their darkest secret :" << std::endl;
        std::getline(std::cin, cup);
        if (cup != "")
        {
            this->contacts[this->index % 8].set_secret(cup);
            std::cout << "+ darkest secret added" << std::endl;
        }
    }
    cup = "";
    while (cup == "")
    {
        std::cout << "*Please enter their Phonenumber :" << std::endl;
        std::getline(std::cin, cup);
        if (cup != "")
        {
            this->contacts[this->index % 8].set_num(cup);
            std::cout << "+ Phonenumber added "<< std::endl;
        }
    }
    this->index++;
}

static std::string format_field(const std::string s)
{
    if (s.size() > 10)
        return s.substr(0, 9) + ".";
    return std::string(10 - s.size(), ' ') + s;
}
// if s = abc;
// this returns 10 - size = 10 - 3 = 7, so 7 * ' ' = "        abc";
// Std::string is not a function. It’s a constructor
//std::string(20 - s.size(), '+') + s => +++++++++++++++++abc


void Phonebook::display(Contact c)
{
    if (c.get_fname().empty())
    {
        std::cout << "-Contact does not exist or Failed to load." << std::endl;
        return;
    }
    std::cout << "First Name     : " << c.get_fname() << std::endl;
    std::cout << "Last Name      : " << c.get_lname() << std::endl;
    std::cout << "Nickname       : " << c.get_nickname() << std::endl;
    std::cout << "Phone Number   : " << c.get_num() << std::endl;
    std::cout << "Darkest Secret : " << c.get_secret() << std::endl;
}


void Phonebook::display_all()
{
    int i;

    i = 0;
    std::cout
        << "index    |Firstname |Lastname  |"
        << "Nickname  |" << std::endl <<
        "-------------------------------------------" << std::endl;
    while (i < 8)
    {
        if (!contacts[i].get_fname().empty())
        {
            std::cout
                << i + 1 << "        " << "|"
                << format_field(contacts[i].get_fname()) << "|"
                << format_field(contacts[i].get_lname()) << "|"
                << format_field(contacts[i].get_num()) << "|"
                << std::endl;
        }
        i++;
    }
}

void Phonebook::search(void)
{
    std::string cup;

    this->display_all();

    while (std::getline(std::cin, cup))
    {
        std::cout << "* Please enter an index from 1 to 8" << std::endl;

        if (cup.empty())
            continue;

        if (cup.size() != 1 || cup[0] < '1' || cup[0] > '8')
        {
            std::cout << "- try again ... between 1 and 8" << std::endl;
            continue;
        }

        int index = cup[0] - '1';

        if (this->contacts[index].get_fname().empty())
        {
            std::cout << "- Contact does not exist or Failed to load." << std::endl;
            return;
        }

        this->display(this->contacts[index]);
        return;
    }
}
