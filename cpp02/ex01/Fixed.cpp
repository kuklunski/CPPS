/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 02:34:15 by ylemkere          #+#    #+#             */
/*   Updated: 2025/12/14 02:34:15 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_bits = 8;

// Default constructor
Fixed::Fixed() : _v(0)
{
    std::cout << "Default constructor called" << "\n";
}

// Deconstructor
Fixed::~Fixed()
{
    std::cout << "Deconstructor called" << "\n";
}

// Copy constructor
Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << "\n";
    *this = other;
}

// Copy assignment operator
Fixed& Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << "\n";
    if (this != &other)
        _v = other.getRawBits();
    return (*this);
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << "\n";
    return (_v);
}

void Fixed::setRawBits( int const raw )
{
    std::cout << "setRawBits called" << "\n";
    _v = raw;
}

Fixed::Fixed(const int x)
{
    std::cout << "Int constructor called" << "\n";
    _v = x << _bits;
}

Fixed::Fixed(const float y)
{
    std::cout << "float constructor called" << "\n";
    _v = roundf(y * (1 << _bits));
}

float Fixed::toFloat( void ) const
{
    return _v / (float)(1 << _bits);
}

int Fixed::toInt() const 
{
    return (_v >> _bits);
}

std::ostream& operator<<(std::ostream& Cout, const Fixed& obj)
{
    Cout << obj.toFloat();
    return Cout;
}