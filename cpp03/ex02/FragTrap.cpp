/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 04:19:24 by ylemkere          #+#    #+#             */
/*   Updated: 2025/12/17 04:19:24 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Yasser")
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    _maxHp = 100;
    std::cout << "FragTrap Default Constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    _maxHp = 100;
    std::cout << "Parameterized FragTrap constructor called with name: " << _Name << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) :  ClapTrap(other)
{
	std::cout << "FragTrap Copy constructor called\n";
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	std::cout << "FragTrap Copy assignment constructor called\n";
	this->_Name = other._Name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
    this->_maxHp = other._maxHp;
	return (*this);
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap Destructor called\n";
}

void FragTrap::attack(const std::string& target)
{
    if (getHitPoints() <= 0 || getEnergyPoints() <= 0)
    {
        std::cout << "health or energy too low. FragTrap '"<< getName() << "' can't attack\n";
        return ;
    }
    std::cout << "FragTrap '"<< getName() << "' attacks " << target << " , causing " << getAttackDamage() <<" points of damage!\n";
    _energyPoints = _energyPoints - 1;
}

void FragTrap::highFivesGuys(void)
{
    if (getHitPoints() <= 0)
        std::cout << "a dead FragTrap cannot highfive \n";
    else
        std::cout << "The biggest highfive from " << getName() << " !!!\n";
}