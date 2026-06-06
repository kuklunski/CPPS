/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 15:35:42 by ylemkere          #+#    #+#             */
/*   Updated: 2026/02/18 15:35:42 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"
#include "Form.hpp"

int main()
{
    std::cout << "---- Default Constructor ----\n";
    Form a;

    std::cout << "\n---- Parameter Constructor ----\n";
    Form b("Contract b", true, 50, 25);

    std::cout << "\n---- Copy Constructor ----\n";
    Form c(b);

    std::cout << "\n---- Assignment Operator ----\n";
    a = b;

    std::cout << "\n---- << overloading -> print a ----\n";
    std::cout << a << "\n";
    std::cout << "\n---- << overloading -> print b ----\n";
    std::cout << b << "\n";
    std::cout << "\n---- Getters ----\n";
    std::cout << "Name: " << b.getName() << std::endl;
    std::cout << "Signed: " << b.getSigned() << std::endl;
    std::cout << "Sign grade: " << b.getSignGrade() << std::endl;
    std::cout << "Exec grade: " << b.getExecGrade() << std::endl;

    std::cout << "\n---- Try / Catch starts ----\n";
    try {
        Form j("Alice",false, 10, 120);
        Form i("Tom", false, 10, 20);
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    Form k("Bob", false, 11, 10);
    try {
        std::cout << "\n---- << overloading -> print k before ----\n";
        std::cout << k << "\n";
        Bureaucrat bt1("bobby", 12);
        k.beSigned(bt1);
    }
    catch (const std::exception& e)
    {
        std::cout << "----> " << e.what() << std::endl;
    }

    std::cout << "\n---- << overloading -> print k after ----\n";
    std::cout << k << "\n";


    try {
        std::cout << "\n---- Testing signForm ----\n";
        Form aa("exam", false, 100, 1);
        Bureaucrat bb("yassir", 99);
        std::cout << "print aa : " << aa << "\n";
        std::cout << "print bb : " << bb << "\n";
        bb.signForm(aa);
    }
    catch (const std::exception& e)
    {
        std::cout << "----> " << e.what() << std::endl;
    }
    std::cout << "\n---- End of main ----\n";
    return 0;
}
