/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 22:30:27 by ylemkere          #+#    #+#             */
/*   Updated: 2026/02/28 22:30:27 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
    // debugg stuff
template <typename T> void printElement(const T &x) {
    std::cout << x << "";
}

template <typename T> void plus_five(const T &val)
{
    T five;
    five = val + 5;
    std::cout << "value is : " << val << " , value + 5 = " << five << std::endl;
}

int main()
{
    const int x[] = {10, 36, 44, 100, 195};
    char y[] = {'h', 'e', 'l', 'l', 'o'};
    iter(x, 5, plus_five<int>);
    iter(y, 5, printElement<char>);
    std::cout << "\n";
    iter("hopes up", 8, printElement<char>);
    std::cout << "\n";
    return 0;
}