/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 02:54:20 by ylemkere          #+#    #+#             */
/*   Updated: 2025/11/21 02:54:20 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <string>
#include <iostream>
#include "Contact.hpp"

class Phonebook {
    private :
        Contact contacts[8];
        int index;
    public :
        Phonebook(void);
        ~Phonebook(void);
        void    add(void);
        void    search(void);
        void    display(Contact contact);
        void    display_all();
};

#endif