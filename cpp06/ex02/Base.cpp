/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 15:24:59 by ylemkere          #+#    #+#             */
/*   Updated: 2026/04/17 15:24:59 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{
}

Base* Base::generate(void)
{
    int min = 1;
    int max = 3;
    int randomNum;
    randomNum = std::rand() % (max - min + 1) + min;
    if (randomNum == 1) return new A;
    else if (randomNum == 2) return new B;
    else if (randomNum == 3) return new C;
    else return NULL;
}

void Base::identify(Base* p)
{
    A* aptr = dynamic_cast<A*>(p);
    if (aptr)
        std::cout << "A" << std::endl;
    B* bptr = dynamic_cast<B*>(p);
    if (bptr)
        std::cout << "B" << std::endl;
    C* cptr = dynamic_cast<C*>(p);
    if (cptr)
        std::cout << "C" << std::endl; 
}

// if the cast does not succeed it throws an exception of type bad_cast
void Base::identify(Base& p)
{
    try
    {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "A" << std::endl;
    }
    catch(const std::exception& e)
    {
    }
    try
    {
        B& b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "B" << std::endl;
    }
    catch(const std::exception& e)
    {
    }
    try
    {
        C& c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "C" << std::endl;
    }
    catch(const std::exception& e)
    {
    }
}