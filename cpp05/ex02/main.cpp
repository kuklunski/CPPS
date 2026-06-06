/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 21:18:54 by ylemkere          #+#    #+#             */
/*   Updated: 2026/02/20 21:18:54 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

int main ()
{
    std::cout << "Main executed successfully.\n";
    // shrubbery sign 145, execute 137  
    // robotomy sign 72, execute 45
    // Presidentail sign 25, execute 5
    Bureaucrat b1("yassir", 135);
    ShrubberyCreationForm s("shss");
    b1.signForm(s);
    b1.executeForm(s);

    std::srand(std::time(NULL));
    RobotomyRequestForm r("Robotttt");
    Bureaucrat b2("omar", 42);
    b2.signForm(r);
    b2.executeForm(r);

    PresidentialPardonForm p("Prrrr");
    Bureaucrat b3("abdo", 5);
    b3.signForm(p);
    b3.executeForm(p);
    return 0;
}