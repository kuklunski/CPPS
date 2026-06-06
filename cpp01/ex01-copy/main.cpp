/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 17:16:36 by ylemkere          #+#    #+#             */
/*   Updated: 2025/11/29 17:16:36 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main ()
{
    Zombie *zombie_horde;
    int N = 5;
    std::string name = "yasser";

    zombie_horde = zombieHorde(N, name);
    if (zombie_horde == NULL)
		return (1);
	for (int i = 0; i < N; ++i)
		zombie_horde[i].announce();
	delete[] zombie_horde;
    return (0);
}