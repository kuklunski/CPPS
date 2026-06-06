/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 20:11:54 by ylemkere          #+#    #+#             */
/*   Updated: 2026/02/21 20:11:54 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
    private :
        const std::string target;
    public :
        void execute(Bureaucrat const & executor) const;
        RobotomyRequestForm();
        ~RobotomyRequestForm();
        RobotomyRequestForm(const std::string& trg);
        RobotomyRequestForm(const RobotomyRequestForm &origin);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& origin);
        std::string getTarget();
};

#endif