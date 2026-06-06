/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 04:25:52 by ylemkere          #+#    #+#             */
/*   Updated: 2025/11/23 04:25:52 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>
#include <iostream>

class Contact {
    private :
        std::string _first_name;
        std::string _last_name;
        std::string _nickname;
        std::string	_darkest_secret;
        std::string	_phone_num;
    public :
        std::string get_fname(void);
        std::string get_lname(void);
        std::string get_nickname(void);
        std::string get_secret(void);
        std::string get_num(void);
        void    set_fname(std::string str);
        void    set_lname(std::string str);
        void    set_nickname(std::string str);
        void    set_secret(std::string str);
        void    set_num(std::string str);
};

#endif