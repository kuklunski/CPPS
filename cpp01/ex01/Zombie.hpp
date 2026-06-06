/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 23:37:45 by ylemkere          #+#    #+#             */
/*   Updated: 2025/12/02 23:37:45 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
    public :
        Zombie();
        ~Zombie();
        void announce( void );
        void set_name(std::string name);
    private :
        std::string _name;
};

Zombie* zombieHorde( int N, std::string name );

#endif