/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 23:03:59 by ylemkere          #+#    #+#             */
/*   Updated: 2025/12/14 23:03:59 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_bits = 8;

Fixed::Fixed() : _v(0)
{
    std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int x)
{
    std::cout << "int constructor called\n";
    _v = x << _bits;
}

Fixed::Fixed(const float y)
{
    std::cout << "float constructor called\n";
    _v = roundf(y * (1 << _bits));
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called\n";
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called\n";
    if (this != &other)
    {
        _v = other.getRawBits();
    }
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Deconstructor called\n";
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called\n";
    return (_v);
}

void Fixed::setRawBits( int const raw )
{
    std::cout << "setRawBits called" << "\n";
    _v = raw;
}

float Fixed::toFloat( void ) const
{
    return _v / (float)( 1 << _bits);
}

int Fixed::toInt( void ) const
{
    return (_v >> _bits);
}

std::ostream& operator<<(std::ostream& Cout, const Fixed& obj)
{
    Cout << obj.toFloat();
    return Cout;
}

bool Fixed::operator<(const Fixed& other) const
{
    std::cout << "'<' operator called\n";
    return (_v < other._v);
}

bool Fixed::operator>(const Fixed& other) const
{
    std::cout << "'>' operator called\n";
    return (_v > other._v);
}

bool Fixed::operator>=(const Fixed& other) const
{
    std::cout << "'>=' operator called\n";
    return (_v >= other._v);
}

bool Fixed::operator<=(const Fixed& other) const
{
    std::cout << "'<=' operator called\n";
    return (_v <= other._v);
}

bool Fixed::operator==(const Fixed& other) const
{
    std::cout << "'==' operator called\n";
    return (_v == other._v);
}

bool Fixed::operator!=(const Fixed& other) const
{
    std::cout << "'!=' operator called\n";
    return (_v != other._v);
}

Fixed Fixed::operator+(const Fixed& other) const
{
    std::cout << "'+' operator called\n";
    Fixed result;
    result.setRawBits(this->_v + other._v);
    return (result);
}

Fixed Fixed::operator-(const Fixed &other) const
{
    std::cout << "'-' operator called \n";
    Fixed result;
    result.setRawBits(this->_v - other._v);
    return (result);
}

Fixed Fixed::operator*(const Fixed &other) const
{
    std::cout << "'*' operator called \n";
    Fixed result;
    result.setRawBits((this->_v * other._v) >> _bits);
    return result;
}

Fixed Fixed::operator/(const Fixed &other) const
{
    std::cout << "'/' operator called \n";
    Fixed result;
    result.setRawBits((this->_v << _bits) / other._v);
    return result;
}

Fixed Fixed::operator++()
{
	this->_v++;
	return (*this);
}

Fixed Fixed::operator--()
{
	this->_v--;
	return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    this->_v++;
    return temp; 
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    this->_v--;
    return temp; 
}
