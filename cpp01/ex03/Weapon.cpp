/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 02:09:32 by ylemkere          #+#    #+#             */
/*   Updated: 2025/12/03 02:09:32 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
    _type = type;
    std::cout << "Weapon constructor called \n";
}

const std::string& Weapon::getType()
{
    return (this->_type);
}
void Weapon::setType(const std::string newType)
{
    this->_type = newType;
}

Weapon::~Weapon()
{
    std::cout << "Weapon Deconstructor called \n";
}