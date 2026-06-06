/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 17:19:19 by ylemkere          #+#    #+#             */
/*   Updated: 2025/11/29 17:19:19 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
    private :
        std::string _name;
    public :
        Zombie();
        ~Zombie();
        void announce( void );
        void set_name(std::string name);
};
Zombie* zombieHorde( int N, std::string name );

#endif