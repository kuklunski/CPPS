/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 23:45:31 by ylemkere          #+#    #+#             */
/*   Updated: 2025/12/02 23:45:31 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie* zombieHorde; 
    zombieHorde = new Zombie[N];
    int i = 0;
    while (i < N)
    {
        zombieHorde[i].set_name(name);
        zombieHorde[i].announce();
        i++;
    }
    return (zombieHorde);
}