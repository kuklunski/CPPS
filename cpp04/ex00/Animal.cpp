/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 22:34:21 by ylemkere          #+#    #+#             */
/*   Updated: 2026/01/12 22:34:21 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Default Animal")
{
    std::cout << "Animal default constructor called\n";
}

Animal::Animal(const std::string &name) : type(name)
{
    std::cout << "Animal Parameterized constructor called\n";
}

Animal::Animal(const Animal& original) : type(original.type)
{
    std::cout << "Animal Copy constructor called\n";
}

Animal &Animal::operator=(const Animal &original)
{
    if (this != &original)
    {
        type = original.type;
    }
    std::cout << "Animal Copy assignment operator called\n";
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal Destructor called\n";
}

void Animal::makeSound() const
{
    std::cout << "-> Animal Sound !\n";
}

std::string Animal::getType() const
{
    return this->type;
}

void Animal::set_type(std::string value)
{
    this->type = value;
}
