/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 22:34:11 by ylemkere          #+#    #+#             */
/*   Updated: 2026/01/12 22:34:11 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Dog.hpp"

class Dog : public Animal
{
    public :
        Dog();
        Dog(const std::string &value);
        Dog(const Dog& original);
        Dog &operator=(const Dog& original);
        void makeSound() const;
        std::string getType() const;
        void set_type(std::string value);
        ~Dog();
};
#endif