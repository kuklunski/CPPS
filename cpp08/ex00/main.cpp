/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 02:30:05 by ylemkere          #+#    #+#             */
/*   Updated: 2026/04/11 02:30:05 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
    std::vector<int> v1;
    v1.push_back( 1 );
    v1.push_back( 2 );
    v1.push_back( 3 );
    v1.push_back( 4 );
    v1.push_back( 5 );
    v1.push_back( 6 );
    v1.push_back( 7 );
    v1.push_back( 8 );
    try {
        std::vector<int>::iterator x = easyfind(v1, 6);
        if (x != v1.end())
            std::cout << "found : " << *x << "\n";
        x = easyfind(v1, 1500);
    }
    catch (const std::exception &e) {
        std::cout << "caught exception : " << e.what() << std::endl;
    }


    return 0;
}