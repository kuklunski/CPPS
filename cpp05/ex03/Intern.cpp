/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 21:32:23 by ylemkere          #+#    #+#             */
/*   Updated: 2026/02/23 21:32:23 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "Intern constructor called\n";
}

Intern::~Intern()
{
    std::cout << "Intern destructor called\n";
}

Intern::Intern(const Intern &origin)
{
    std::cout << "Intern copy constructor called\n";
}

Intern& Intern::operator=(const Intern &origin)
{
    std::cout << "Intern copy assignment operator called\n";
    return *this;
}

AForm* Intern::createShrubbery(const std::string& target)
{
    return new ShrubberyCreationForm(target);
}
AForm* Intern::createRobotomy(const std::string& target)
{
    return new RobotomyRequestForm(target);
}
AForm* Intern::createPresidential(const std::string& target)
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& name, const std::string& target)
{
    std::string names[3] = {
        "shrubbery",
        "robotomy",
        "presidential"
    };

    AForm* (Intern::*creators[3])(const std::string&) = {
        &Intern::createShrubbery,
        &Intern::createRobotomy,
        &Intern::createPresidential
    };

    for (int i = 0; i < 3; ++i)
    {
        if (name == names[i])
            return (this->*creators[i])(target);
    }

    throw UnknownFormException();
}

const char* Intern::UnknownFormException::what() const throw()
{
    return "Form name does not exist";
}