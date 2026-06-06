/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 21:24:20 by ylemkere          #+#    #+#             */
/*   Updated: 2026/02/21 21:24:20 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
    private :
        const std::string target;

    public :
        void execute(Bureaucrat const & executor) const;
        PresidentialPardonForm();
        ~PresidentialPardonForm();
        PresidentialPardonForm(const std::string &trg);
        PresidentialPardonForm(const PresidentialPardonForm& origin);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& origin);
        std::string getTarget();
};

#endif