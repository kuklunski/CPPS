/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 21:17:51 by ylemkere          #+#    #+#             */
/*   Updated: 2026/02/21 21:17:51 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (executor.getGrade() > getExecGrade())
        throw AForm::GradeTooLowException();
    if (getSigned() == false)
        throw AForm::FormNotSigned();
    std::cout << "--- > "<< target << " has been pardoned by Zaphod Beeblebrox\n";
}

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", false, 25, 5), target("default President Name")
{
    std::cout << "PPF default constructor called\n";
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PPF destructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &trg) : AForm("PresidentialPardonForm", false, 25, 5), target(trg)
{
    std::cout << "PPF constructor with parameters called\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& origin)
    : AForm(origin), target(origin.target)
{
    std::cout << "PPF copy constructor called\n";
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& origin)
{
    std::cout << "PPF copy assignment operator called\n";

    if (this != &origin)
        AForm::operator=(origin);

        return *this;
}

std::string PresidentialPardonForm::getTarget()
{
    return target;
}