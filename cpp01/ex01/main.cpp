/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 23:37:22 by ylemkere          #+#    #+#             */
/*   Updated: 2025/12/02 23:37:22 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main (void)
{
    Zombie* zizou;
    int N = 5;

    zizou = zombieHorde(N, "yasser");
    for (int i = 0; i < N; i++)
    {
        std::cout << i << " : ";
        zizou[i].announce();
    }
    zizou[3].announce();
    zizou[1].announce();
    delete[] zizou;
    return (0);
}