/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 21:12:47 by ylemkere          #+#    #+#             */
/*   Updated: 2026/02/23 21:12:47 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
    private :
        AForm* createShrubbery(const std::string& target);
        AForm* createRobotomy(const std::string& target);
        AForm* createPresidential(const std::string& target);

    public :
        AForm* makeForm(const std::string &form, const std::string &target);
        class UnknownFormException : public std::exception
        {
            public :
                const char* what() const throw();
        };
        Intern();
        ~Intern();
        Intern(const Intern &origin);
        Intern& operator=(const Intern &origin);
};

#endif