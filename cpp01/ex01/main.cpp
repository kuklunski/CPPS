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
    Zombie* zizi;
    int N = 5;

    zizi = zombieHorde(N, "yasser");
    delete[] zizi;
    return (0);
}