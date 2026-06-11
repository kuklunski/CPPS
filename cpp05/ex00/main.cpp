/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 18:34:35 by ylemkere          #+#    #+#             */
/*   Updated: 2026/02/14 18:34:35 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"

int main ()
{
    Bureaucrat b1;
    std::cout << b1;
    try {
        std::cout << "start try\n";
        Bureaucrat a("Bob", 10);
        // Bureaucrat f("test", 1);
        // f.incrementGrade();

        Bureaucrat g("test2", 150);
        g.decrementGrade();
        std::cout << "Never reached\n";
        //Bureaucrat b("Alice", 151);
        //Bureaucrat c("Tom", 20);
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 1;
}