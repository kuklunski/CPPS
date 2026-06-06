/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 21:19:05 by ylemkere          #+#    #+#             */
/*   Updated: 2026/02/20 21:19:05 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("default name"), _signed(false), sign_grade(150), exec_grade(150)
{
    std::cout << "AForm default constructor called\n";
}
AForm::~AForm()
{
    std::cout << "AForm destructor called\n";
}
AForm::AForm(const AForm &origin) : _name(origin._name), _signed(origin._signed), sign_grade(origin.sign_grade), exec_grade(origin.exec_grade)
{
    std::cout << "AForm copy constructor called\n";
}

AForm::AForm(const std::string name, bool sign, const int sg_grd, const int exc_grd)
    : _name(name),
      _signed(sign),
      sign_grade(sg_grd),
      exec_grade(exc_grd)
{
    std::cout << "AForm parameterized constructor called\n";
    if (sg_grd < 1 || exc_grd < 1)
        throw GradeTooHighException();
    if (sg_grd > 150 || exc_grd > 150)
        throw GradeTooLowException();
}
void AForm::beSigned(const Bureaucrat& bt)
{
    if (bt.getGrade() <= this->sign_grade)
    {
        this->_signed = true;
        std::cout << "--- > Form signed successfully !\n";
    }
    else
        throw GradeTooLowException();
}

AForm& AForm::operator=(const AForm &origin)
{
    std::cout << "AForm copy assignment operator called\n";

    if (this != &origin)
        this->_signed = origin._signed;
    
    return *this;
}
std::string AForm::getName() const
{
    return _name;
}
bool AForm::getSigned() const
{
    return _signed;
}
int AForm::getSignGrade() const
{
    return sign_grade;
}
int AForm::getExecGrade() const
{
    return exec_grade;
}

std::ostream& operator<<(std::ostream& Cout, const AForm& fm)
{
    Cout << "AForm name: " << fm.getName() << "\n"
       << "Signed: " << (fm.getSigned() ? "Yes" : "No") << "\n"
       << "Grade required to sign: " << fm.getSignGrade() << "\n"
       << "Grade required to execute: " << fm.getExecGrade();

    return Cout;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade too low";
}

const char* AForm::FormNotSigned::what() const throw()
{
    return "This Form is not signed !";
}