/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 22:34:13 by ylemkere          #+#    #+#             */
/*   Updated: 2026/01/12 22:34:13 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << "Dog Default constructor called\n";
}

Dog::Dog(const std::string &value) : Animal(value)
{
    std::cout << "Dog Parameterized constructor called\n";
}

Dog::Dog(const Dog& original) : Animal(original.type)
{
    std::cout << "Dog Copy constructor called\n";
}

Dog &Dog::operator=(const Dog& original)
{
    if (this != &original)
    {
        this->type = original.type;
    }
    std::cout << "Dog Copy assignment operator called\n";
    return *this;
}

void Dog::makeSound() const
{
    std::cout << getType() << " barks\n";
}

std::string Dog::getType() const
{
    return this->type;
}

void Dog::set_type(std::string value)
{
    this->type = value;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called\n";
}