/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 02:09:38 by ylemkere          #+#    #+#             */
/*   Updated: 2025/12/03 02:09:38 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

void HumanB::setWeapon(Weapon& arme)
{
    weapon = &arme;
}

HumanB::HumanB(std::string name) : weapon(NULL)
{
    _name = name;
}

HumanB::~HumanB()
{

}

void HumanB::attack()
{
    if (weapon)
        std::cout << _name << " attacks with their " << weapon->getType() << std::endl;
    else
        std::cout << _name << " has no weapon!" << std::endl;
}