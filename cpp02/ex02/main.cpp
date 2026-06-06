/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 23:04:05 by ylemkere          #+#    #+#             */
/*   Updated: 2025/12/14 23:04:05 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
/*
int main( void ) 
{
        Fixed a;
        Fixed const b( 10 );
        Fixed const c( 42.42f );
        Fixed const d( b );

        a = Fixed( 1234.4321f );
    
        std::cout << "a is " << a << std::endl;
        std::cout << "b is " << b << std::endl;
        std::cout << "c is " << c << std::endl;
        std::cout << "d is " << d << std::endl;

        std::cout << "a is " << a.toInt() << " as integer" << std::endl;
        std::cout << "b is " << b.toInt() << " as integer" << std::endl;
        std::cout << "c is " << c.toInt() << " as integer" << std::endl;
        std::cout << "d is " << d.toInt() << " as integer" << std::endl;
        std::cout << "a is " << a.toFloat() << " as float" << std::endl;
        std::cout << "b is " << b.toFloat() << " as float" << std::endl;
        std::cout << "c is " << c.toFloat() << " as float" << std::endl;
        std::cout << "d is " << d.toFloat() << " as float" << std::endl;
    std::cout << "\n\nif we didnt use the Fixed class \n";
    float a_f;
    const float b_f = 10;
    const float c_f = 42.42f;
    const float d_f = b_f;

    a_f = 1234.4321f;

    std::cout << "---- Floats ----" << std::endl;
    std::cout << "a_f = " << a_f << std::endl;
    std::cout << "b_f = " << b_f << std::endl;
    std::cout << "c_f = " << c_f << std::endl;
    std::cout << "d_f = " << d_f << std::endl;

    std::cout << "Typecast to int:" << std::endl;
    std::cout << "a_f as int = " << (int)a_f << std::endl;
    std::cout << "c_f as int = " << (int)c_f << std::endl;

    std::cout << "Typecast back to float:" << std::endl;
    std::cout << "a_f after int cast = " << (float)(int)a_f << std::endl;
    std::cout << "c_f after int cast = " << (float)(int)c_f << std::endl;

    std::cout << "\n---- Comparisons ----" << std::endl;

    std::cout << "a < b : " << (a < b) << std::endl;
    std::cout << "a > b : " << (a > b) << std::endl;
    std::cout << "a <= c : " << (a <= c) << std::endl;
    std::cout << "a >= c : " << (a >= c) << std::endl;
    std::cout << "a == c : " << (a == c) << std::endl;
    std::cout << "a != b : " << (a != b) << std::endl;

    std::cout << "\n---- Arithmetic ----" << std::endl;

    std::cout << "a + b = " << (a + b) << std::endl;
    std::cout << "a - b = " << (a - b) << std::endl;
    std::cout << "a * b = " << (a * b) << std::endl;
    std::cout << "a / b = " << (a / b) << std::endl;

    Fixed i;
    Fixed const j( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << i << std::endl;
    std::cout << ++i << std::endl;
    std::cout << i << std::endl;
    std::cout << i++ << std::endl;
    std::cout << i << std::endl;
    std::cout << j << std::endl;

    return 0;
} */
int main( void ) 
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    
    return 0;
}