/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 01:20:04 by ylemkere          #+#    #+#             */
/*   Updated: 2025/12/14 01:20:04 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>

class Fixed
{
    private :
        int _v;
        static const int _bits;
    public :
        Fixed();
        ~Fixed();
        Fixed(const Fixed& other);
        Fixed&  operator=(const Fixed &other);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
};
#endif