/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 02:22:13 by ylemkere          #+#    #+#             */
/*   Updated: 2025/11/21 02:22:13 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <cctype>
#include <iostream>

int main (int ac, char **av)
{
    char c;
    int i;
    int j;

    if (ac > 1)
    {
        i = 1;
        while (av[i])
        {
            j = 0;
            while (av[i][j])
            {
                c = toupper(av[i][j]);
                std::cout << c;
                j++;
            }
            if (i != ac - 1)
            {
                std::cout << " ";
            }
            i++;
        }
        std::cout << std::endl;
    }
    else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return (0);
}