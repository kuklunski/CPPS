/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 01:45:58 by ylemkere          #+#    #+#             */
/*   Updated: 2026/01/13 01:45:58 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include <iostream>
#include <string>

class WrongCat : public WrongAnimal
{
public:
    WrongCat();                          // default
    WrongCat(const std::string &value);  // parameterized
    WrongCat(const WrongCat &other);     // copy constructor
    WrongCat &operator=(const WrongCat &other); // copy assignment
    ~WrongCat();                         // destructor

    void makeSound() const;              // NOT virtual
};

#endif
