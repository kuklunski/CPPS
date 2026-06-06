/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 00:29:52 by ylemkere          #+#    #+#             */
/*   Updated: 2025/12/17 00:29:52 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _Name("Yasser"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _Name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "Parameterized ClapTrap constructor called with name :" << getName() << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) :  _Name(other._Name), _hitPoints(other._hitPoints),
	_energyPoints(other._energyPoints), _attackDamage(other._attackDamage)
{
	std::cout << "ClapTrap Copy constructor called\n";
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "ClapTrap Copy assignment constructor called\n";
	this->_Name = other._Name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called\n";
}

void ClapTrap::attack(const std::string& target)
{
    if (getHitPoints() <= 0 || getEnergyPoints() <= 0)
    {
        std::cout << "health or energy too low. ClapTrap '"<< getName() << "' can't attack\n";
        return ;
    }
    std::cout << "ClapTrap '"<< getName() << "' attacks " << target << " , causing " << getAttackDamage() <<" points of damage!\n";
    _energyPoints = _energyPoints - 1;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (getHitPoints() <= 0)
    {
        std::cout << "No damage taken, ClapTrap '"<< getName() << "' is already dead\n";
        return ;
    }

    if (amount >= getHitPoints())
        _hitPoints = 0;
    else
        _hitPoints -= amount;

    std::cout << "ClapTrap '" << getName() << "' takes " << amount << " points of damage!\n";
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_hitPoints >= 10)
    {
        std::cout << "no need to repair, '" << getName() << "' is already at 10 HP.\n";
        return;
    }
    else if (_hitPoints <= 0 || _energyPoints <= 0)
    {
        std::cout << "ClapTrap '" << getName() << "' cannot be repaired.\n";
        return;
    }

    if (_hitPoints + amount > 10)
        _hitPoints = 10;
    else
        _hitPoints += amount;

    _energyPoints--;

    std::cout << "ClapTrap '" << getName() << "' repairs itself for " << amount << " hit points.\n";
}

std::string ClapTrap::getName()
{
    return (_Name);
}

unsigned int ClapTrap::getHitPoints()
{
    return (_hitPoints);
}
unsigned int ClapTrap::getEnergyPoints()
{
    return (_energyPoints);
}
unsigned int ClapTrap::getAttackDamage()
{
    return (_attackDamage);
}