/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 02:09:25 by ylemkere          #+#    #+#             */
/*   Updated: 2025/12/03 02:09:25 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
    public :
        void    attack();
        HumanB(std::string name);
        ~HumanB();
        void setWeapon(Weapon& arme);

    private :
        std::string _name;
        Weapon* weapon;
};

#endif