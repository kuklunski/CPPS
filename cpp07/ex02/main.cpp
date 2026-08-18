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
#include <string>

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

    // bigger than length
    try {
        std::cout << arr[8] << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << ": bigger than length" << std::endl;
    }
    // negative number
    try {
        std::cout << arr[-5] << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << ": negative number" << std::endl;
    }

    // equal to length
    try {
        std::cout << arr[5] << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << ": equal to length" << std::endl;
    }
    std::cout << "siiiize :::: "<< arr.size() << "\n";

    // same tests, but with a complex type (std::string) instead of int
    Array<std::string> strArr(3);
    strArr[0] = "hello";
    strArr[1] = "world";
    strArr[2] = "!";

    for (int i = 0; i < 3; i++)
        std::cout << strArr[i] << std::endl;

    Array<std::string> strCopy(strArr);
    strCopy[0] = "changed";
    std::cout << "original[0] : " << strArr[0] << std::endl;
    std::cout << "copy[0]     : " << strCopy[0] << std::endl;

    Array<std::string> strAssigned;
    strAssigned = strArr;
    std::cout << "assigned[1] : " << strAssigned[1] << std::endl;

    try {
        std::cout << strArr[3] << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << ": out of bounds on string array" << std::endl;
    }
    std::cout << "string array siiiize :::: " << strArr.size() << "\n";
}
