/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 21:34:22 by ylemkere          #+#    #+#             */
/*   Updated: 2026/03/02 21:34:22 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main ()
{
    int x = 14;
    Array<int> test;
    Array<int> test2(x);
    std::cout << "siiiize :::: "<< test2.size() << "\n"; 
    Array<int> test3(test2);
    Array<int> test4(0);
    test2 = test;
    Array<int> arr(5);

    for (int i = 0; i < 5; i++)
        std::cout << arr[i] << std::endl;
    std::cout << "siiiize :::: "<< arr.size() << "\n"; 
}
