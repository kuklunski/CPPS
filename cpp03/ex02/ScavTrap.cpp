/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 03:35:17 by ylemkere          #+#    #+#             */
/*   Updated: 2025/12/17 03:35:17 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Yasser")
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    _maxHp = 100;
    _gateMode = false;
    std::cout << "ScavTrap Default Constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    _maxHp = 100;
    _gateMode = false;
    std::cout << "Parameterized ScavTrap constructor called with name: " << _Name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) :  ClapTrap(other)
{
	std::cout << "ScavTrap Copy constructor called\n";
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "ScavTrap Copy assignment constructor called\n";
	this->_Name = other._Name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
    this->_maxHp = other._maxHp;
    this->_gateMode = other._gateMode;
	return (*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor called\n";
}

void ScavTrap::attack(const std::string& target)
{
    if (getHitPoints() <= 0 || getEnergyPoints() <= 0)
    {
        std::cout << "health or energy too low. ScavTrap '"<< getName() << "' can't attack\n";
        return ;
    }
    std::cout << "ScavTrap '"<< getName() << "' attacks " << target << " , causing " << getAttackDamage() <<" points of damage!\n";
    _energyPoints = _energyPoints - 1;
}

void ScavTrap::gateMode()
{
    if (_gateMode == false)
    {
        _gateMode = true;
        std::cout << "Gate Keeper Mode ON\n";
    }
    else
    {
        _gateMode = false;
        std::cout << "Gate Keeper Mode OFF\n";        
    }
}