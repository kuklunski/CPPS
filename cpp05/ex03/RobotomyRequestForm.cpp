/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 20:11:51 by ylemkere          #+#    #+#             */
/*   Updated: 2026/02/21 20:11:51 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (executor.getGrade() > getExecGrade())
        throw AForm::GradeTooLowException();
    if (getSigned() == false)
        throw AForm::FormNotSigned();
    std::cout << "Tzzz drilling noises... \n";
    if (std::rand() % 2)
        std::cout << "--- > " << target << " has been robotomized successfully\n";
    else
        std::cout << "--- > " << "Robotomy failed\n";
}

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", false, 72, 45), target("default Robot Target")
{
    std::cout << "Robotomy default constructor called\n";
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "Robotomy destructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &trg) : AForm("RobotomyRequestForm", false, 72, 45) , target(trg)
{
    std::cout << "robotomy constructor with parameters called\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& origin)
    : AForm(origin), target(origin.target)
{
    std::cout << "Robotomy copy constructor called\n";
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& origin)
{
    std::cout << "Robotomy copy assignment operator called\n";

    if (this != &origin)
        AForm::operator=(origin);

        return *this;
}

std::string RobotomyRequestForm::getTarget()
{
    return target;
}