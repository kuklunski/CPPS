/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 21:18:59 by ylemkere          #+#    #+#             */
/*   Updated: 2026/02/20 21:18:59 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : name("default name"), grade(1)
{
    std::cout << "Bureaucrat default constructor called\n";
}

Bureaucrat::Bureaucrat(const std::string &str, int grd) : name(str)
{
    std::cout << "Bureaucrat constructor with parameters called\n";
    if (grd < 1)
        throw GradeTooHighException();
    if (grd > 150)
        throw GradeTooLowException();
    grade = grd;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat destructor called\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat &origin) : name(origin.name), grade(origin.grade)
{
    std::cout << "Bureaucrat copy constructor called\n";
}

// name is const, cannot be reassigned
Bureaucrat& Bureaucrat::operator=(const Bureaucrat &origin)
{
    if (this != &origin)
        grade = origin.grade;
    std::cout << "Bureaucrat assignment Operator called\n";
    return (*this);
}

std::string Bureaucrat::getName() const
{
    return(name);
}

int Bureaucrat::getGrade() const
{
    return (grade);
}

void Bureaucrat::incrementGrade()
{
    if (this->grade <= 1)
        throw GradeTooHighException();
    grade--;
}

void Bureaucrat::decrementGrade()
{
    if (this->grade >= 150)
        throw GradeTooLowException();
    grade++;
}

std::ostream& operator<<(std::ostream& Cout, const Bureaucrat& bt)
{
    Cout << bt.getName() << ", bureaucrat grade " << bt.getGrade() << ".\n";
    return Cout;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too low";
}

void Bureaucrat::signForm(AForm& form)
{
    try{
        form.beSigned(*this);
        std::cout << "--- > "
                  << this->getName() << " signed "
                  << form.getName() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "--- > "
                  << this->getName() << " couldn't sign "
                  << form.getName() << " : "
                  << e.what() << std::endl;
    }
}
void Bureaucrat::executeForm(AForm const & form) const
{
    try{
        form.execute(*this);
        std::cout << "--- > "
                  << this->getName() << " executed "
                  << form.getName() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "--- > "
                  << this->getName() << " couldn't execute "
                  << form.getName() << " : "
                  << e.what() << std::endl;
    }
}