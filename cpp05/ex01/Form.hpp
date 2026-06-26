/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 15:37:20 by ylemkere          #+#    #+#             */
/*   Updated: 2026/02/18 15:37:20 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Bureaucrat;

class Form
{
    private :
        const std::string _name;
        bool    _signed;
        const int sign_grade;
        const int exec_grade;
    public :
        Form();
        ~Form();
        Form(const Form &origin);
        Form(const std::string name, const int sg_grd, const int exc_grd);
        Form &operator=(const Form &origin);
        std::string getName() const;
        bool getSigned() const;
        int getSignGrade() const;
        int getExecGrade() const;
        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };
        void beSigned(const Bureaucrat& bt);
};

std::ostream& operator<<(std::ostream& Cout, const Form& fm);
#endif