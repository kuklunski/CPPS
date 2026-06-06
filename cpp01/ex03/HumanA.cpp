/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 02:09:40 by ylemkere          #+#    #+#             */
/*   Updated: 2025/12/03 02:09:40 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& arme) : _name(name), weapon(arme)
{
    std::cout << "HumanA constructor called \n";
}

HumanA::~HumanA()
{
    std::cout << "HumanA Deconstructor called \n";
}

void HumanA::attack()
{
    std::cout << _name << " attacks with their " << weapon.getType() << std::endl;
}