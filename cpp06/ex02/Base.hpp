/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 15:19:51 by ylemkere          #+#    #+#             */
/*   Updated: 2026/04/17 15:19:51 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <ctime> 
#include <cstdlib>

class Base
{
    public :
        virtual ~Base();
        Base* generate(void);
        void identify(Base* p);
        void identify(Base& p);
};

#endif