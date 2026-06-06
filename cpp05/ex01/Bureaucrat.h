/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 15:35:37 by ylemkere          #+#    #+#             */
/*   Updated: 2026/02/18 15:35:37 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>

class Form;

class Bureaucrat
{
    private :
        const std::string name;
        int grade;
    public :
        Bureaucrat();
        ~Bureaucrat();
        Bureaucrat(const std::string &str, int grd);
        Bureaucrat(const Bureaucrat &origin);
        Bureaucrat &operator=(const Bureaucrat &origin);
        std::string getName() const;
        int getGrade() const;
        void incrementGrade(); // incrementing a grade 3 should result in a grade 2
        void decrementGrade(); // decrementing a grade 10 should result in a grade 11
        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };
        void signForm(Form& form);
};

// <name>, bureaucrat grade <grade>.
std::ostream& operator<<(std::ostream& Cout, const Bureaucrat& bt);

#endif