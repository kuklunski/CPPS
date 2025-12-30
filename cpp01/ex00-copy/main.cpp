/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 16:50:57 by ylemkere          #+#    #+#             */
/*   Updated: 2025/11/29 16:50:57 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    Zombie *heap_zombie = newZombie("Heap_Zombie");
    randomChump("Stack_Zombie");
    delete heap_zombie ;
    return (0);
}