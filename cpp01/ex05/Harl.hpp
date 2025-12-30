/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 00:05:02 by ylemkere          #+#    #+#             */
/*   Updated: 2025/12/09 00:05:02 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

class Harl {
    public :
    	Harl();
		~Harl();
        void complain( std::string level );
    private :
        void debug( void );
        void info( void );
        void warning( void );
        void error( void );
};

#endif