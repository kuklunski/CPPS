/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 22:34:19 by ylemkere          #+#    #+#             */
/*   Updated: 2026/01/12 22:34:19 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <string>
#include <iostream>

class Animal
{
    protected :
        std::string type;

    public :
        Animal();
        Animal(const std::string &name);
        Animal(const Animal& original);
        Animal &operator=(const Animal &original);
        virtual ~Animal();
        virtual void makeSound() const;
        std::string getType() const;
        void set_type(std::string value);
};
#endif