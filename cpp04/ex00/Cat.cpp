/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 22:34:17 by ylemkere          #+#    #+#             */
/*   Updated: 2026/01/12 22:34:17 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "Cat Default constructor called\n";
}

Cat::Cat(const std::string &value) : Animal(value)
{
    std::cout << "Cat Parameterized constructor called\n";
}

Cat::Cat(const Cat& original) : Animal(original.type)
{
    std::cout << "Cat Copy constructor called\n";
}

Cat &Cat::operator=(const Cat& original)
{
    if (this != &original)
    {
        this->type = original.type;
    }
    std::cout << "Cat Copy assignment operator called\n";
    return *this;
}

void Cat::makeSound() const
{
    std::cout << getType() << " Meows\n";
}

std::string Cat::getType() const
{
    return this->type;
}

void Cat::set_type(std::string value)
{
    this->type = value;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called\n";
}