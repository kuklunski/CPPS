/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 22:34:15 by ylemkere          #+#    #+#             */
/*   Updated: 2026/01/12 22:34:15 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Cat.hpp"

class Cat : public Animal
{
    public :
        Cat();
        Cat(const std::string &value);
        Cat(const Cat& original);
        Cat &operator=(const Cat& original);
        void makeSound() const;
        std::string getType() const;
        void set_type(std::string value);
        ~Cat();
};
#endif