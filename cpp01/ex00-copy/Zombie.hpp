/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 16:42:47 by ylemkere          #+#    #+#             */
/*   Updated: 2025/11/29 16:42:47 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie {
    public :
        void announce(void);
        Zombie(std::string name);
        ~Zombie();
    private:
        std::string _name;
};
Zombie	*newZombie(std::string name);

void randomChump( std::string name );
#endif