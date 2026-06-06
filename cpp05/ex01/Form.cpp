/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 16:24:42 by ylemkere          #+#    #+#             */
/*   Updated: 2026/02/18 16:24:42 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.h"

Form::Form() : _name("default name"), _signed(false), sign_grade(150), exec_grade(150)
{
    std::cout << "Default constructor called\n";
}
Form::~Form()
{
    std::cout << "Destructor called\n";
}
Form::Form(const Form &origin) : _name(origin._name), _signed(origin._signed), sign_grade(origin.sign_grade), exec_grade(origin.exec_grade)
{
    std::cout << "Copy constructor called\n";
}

Form::Form(const std::string name, bool sign, const int sg_grd, const int exc_grd)
    : _name(name),
      _signed(sign),
      sign_grade(sg_grd),
      exec_grade(exc_grd)
{
    std::cout << "Parameterized constructor called\n";
    if (sg_grd < 1 || exc_grd < 1)
        throw GradeTooHighException();
    if (sg_grd > 150 || exc_grd > 150)
        throw GradeTooLowException();
}
void Form::beSigned(const Bureaucrat& bt)
{
    if (bt.getGrade() <= this->sign_grade)
        this->_signed = true;
    else
        throw GradeTooLowException();
}

Form& Form::operator=(const Form &origin)
{
    std::cout << "Copy assignment operator called\n";

    if (this != &origin)
        this->_signed = origin._signed;
    
    return *this;
}
std::string Form::getName() const
{
    return _name;
}
bool Form::getSigned() const
{
    return _signed;
}
int Form::getSignGrade() const
{
    return sign_grade;
}
int Form::getExecGrade() const
{
    return exec_grade;
}

std::ostream& operator<<(std::ostream& Cout, const Form& fm)
{
    Cout << "Form name: " << fm.getName() << "\n"
       << "Signed: " << (fm.getSigned() ? "Yes" : "No") << "\n"
       << "Grade required to sign: " << fm.getSignGrade() << "\n"
       << "Grade required to execute: " << fm.getExecGrade();

    return Cout;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade too low";
}