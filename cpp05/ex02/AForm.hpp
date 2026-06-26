/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 21:19:03 by ylemkere          #+#    #+#             */
/*   Updated: 2026/02/20 21:19:03 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>

class Bureaucrat;

class AForm
{
    private :
        const std::string _name;
        bool    _signed;
        const int sign_grade;
        const int exec_grade;
    public :
        AForm();
        AForm(const AForm &origin);
        AForm(const std::string name, const int sg_grd, const int exc_grd);
        AForm &operator=(const AForm &origin);
        std::string getName() const;
        bool getSigned() const;
        int getSignGrade() const;
        int getExecGrade() const;

        // Grade Exceptions
        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };

        // FormNotSigned Exception
        class FormNotSigned : public std::exception {
            public :
                const char* what() const throw();
        };

        void beSigned(const Bureaucrat& bt);
        virtual void execute(Bureaucrat const & executor) const = 0;
        virtual ~AForm(); // do not forget
};

std::ostream& operator<<(std::ostream& Cout, const AForm& fm);
#endif