/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 23:04:02 by ylemkere          #+#    #+#             */
/*   Updated: 2025/12/02 23:04:02 by ylemkere         ###   ########.fr       */
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
        void    announce( void );
        Zombie(std::string name);
        ~Zombie();
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif