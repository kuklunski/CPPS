/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 01:36:26 by ylemkere          #+#    #+#             */
/*   Updated: 2026/01/13 01:36:26 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
protected:
    std::string type;

public:
    WrongAnimal();                        // default constructor
    WrongAnimal(const std::string &type); // parameterized constructor
    WrongAnimal(const WrongAnimal &other); // copy constructor
    WrongAnimal &operator=(const WrongAnimal &other); // copy assignment
    ~WrongAnimal();                       // destructor

    void makeSound() const;               // NOT virtual
    std::string get_type() const;
    void set_type(const std::string &value);
};

#endif