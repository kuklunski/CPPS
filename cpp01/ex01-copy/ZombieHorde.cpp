/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 17:29:25 by ylemkere          #+#    #+#             */
/*   Updated: 2025/11/29 17:29:25 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    int i;

    i = 0;
    if (N < 1)
    {
        std::cout << "what horde without Zombies ?" << std::endl;
        return (NULL);
    }
    Zombie  *zombie_horde;
    zombie_horde = new Zombie[N];
    if (zombie_horde == NULL)
    {
        std::cout << "allocation failed !" << std::endl;
    }
    while (i < N)
    {
        zombie_horde[i].set_name(name);
        i++;
    }
    return (zombie_horde);
}