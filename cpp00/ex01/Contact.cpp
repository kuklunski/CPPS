/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 23:11:56 by ylemkere          #+#    #+#             */
/*   Updated: 2025/11/25 23:11:56 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string Contact::get_fname(void)
{
    return (this->_first_name);
}

std::string Contact::get_lname(void)
{
    return (this->_last_name);
}

std::string Contact::get_nickname(void)
{
    return (this->_nickname);
}

std::string Contact::get_secret(void)
{
    return (this->_darkest_secret);
}

std::string Contact::get_num(void)
{
    return (this->_phone_num);
}

void    Contact::set_fname(std::string str)
{
    this->_first_name = str;
    return ;
}
void    Contact::set_lname(std::string str)
{
    this->_last_name = str;
    return ;
}
void    Contact::set_nickname(std::string str)
{
    this->_nickname = str;
    return ;
}
void    Contact::set_secret(std::string str)
{
    this->_darkest_secret = str;
    return ;
}
void    Contact::set_num(std::string str)
{
    this->_phone_num = str;
    return ;
}