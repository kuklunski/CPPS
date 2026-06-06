/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 15:18:31 by ylemkere          #+#    #+#             */
/*   Updated: 2026/04/17 15:18:31 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "C.hpp"
#include "B.hpp"

int main()
{
    // pointer version
    Base* p = new Base();
    Base* ptr;
    int i =0 ;
    std::srand(static_cast<unsigned int>(std::time(0)));
    while (i < 5)
    {
        ptr = p->generate();
        std::cout << "pointer version : ";
        p->identify(ptr);
        std::cout << "reference version : ";
        p->identify(*ptr);
        delete ptr;
        i++;
    }
    delete p;
    return 0;
}