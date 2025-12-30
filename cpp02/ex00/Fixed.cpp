/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 01:20:01 by ylemkere          #+#    #+#             */
/*   Updated: 2025/12/14 01:20:01 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_bits = 8;

Fixed::Fixed() : _v(0)
{
    std::cout << "Default constructor called" << "\n";
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << "\n";
    *this = other;
}

//copy assignement operator
Fixed&  Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << "\n";
    if (this != &other)
        this->_v = other.getRawBits();
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Deconstructor called" << "\n";
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << "\n";
    return (_v);
}

void Fixed::setRawBits( int const raw )
{
    _v = raw;
}