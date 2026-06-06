/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 22:03:55 by ylemkere          #+#    #+#             */
/*   Updated: 2026/02/20 22:03:55 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

bool ShrubberyCreationForm::hasUnprintable(const std::string & str) const
{
    for(int i = 0; i < str.length(); i++)
    {
        if (!std::isprint(static_cast<unsigned char>(str[i])))
            return true;
    }
    return false;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (executor.getGrade() > getExecGrade())
        throw AForm::GradeTooLowException();
    if (getSigned() == false)
        throw AForm::FormNotSigned();
    if (target.empty() || hasUnprintable(target))
    {
        std::ofstream file("default_shrubbery");
        if (!file)
            return ;
        file << "   ^   \n";
        file << "  ^^^  \n";
        file << " ^^^^^ \n";
        file << "   |   \n";
        std::cout << "--- >" << " File default_shrubbery created\n";
        return ;
    }
    std::ofstream file((target + "_shrubbery").c_str());
    if (!file)
        return ;
    file << "   ^   \n";
    file << "  ^^^  \n";
    file << " ^^^^^ \n";
    file << "   |   \n";
    std::cout << "--- > " << target << "_shrubbery file created\n";
}

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", false, 145, 137), target("default Shrub Target")
{
    std::cout << "Shrubbery default constructor called\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "Shrubbery destructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& trg) : AForm("ShrubberyCreationForm", false, 145, 137), target(trg)
{
    std::cout << "Shrubbery Constructor with parameters called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& origin) 
    : AForm(origin), target(origin.target)
{
    std::cout << "Shrubbery Copy constructor called\n";
}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& origin)
{
    std::cout << "Shrubbery Copy assignment operator called\n";
    
    if (this != &origin)
        AForm::operator=(origin);
    
    return *this;
}
std::string ShrubberyCreationForm::getTarget()
{
    return target;
}