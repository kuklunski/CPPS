/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 00:29:39 by ylemkere          #+#    #+#             */
/*   Updated: 2025/12/17 00:29:39 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	std::cout << "### TESTING CLAPTRAP ###\n" << std::endl;
	{
		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		ClapTrap a;
		ClapTrap b("Clap");

		std::cout << "\033[34mTesting\033[0m" << std::endl;
		a.attack("his brother");
        std::cout << a.getName() << " > "<< a.getHitPoints() << " Hp > " << a.getEnergyPoints() << " EnergyPoints.\n";
		a.takeDamage(10);
        std::cout << a.getName() << " > "<< a.getHitPoints() << " Hp > " << a.getEnergyPoints() << " EnergyPoints.\n";
		a.takeDamage(10);
        std::cout << a.getName() << " > "<< a.getHitPoints() << " Hp > " << a.getEnergyPoints() << " EnergyPoints.\n";
		a.beRepaired(5);
        std::cout << a.getName() << " > "<< a.getHitPoints() << " Hp > " << a.getEnergyPoints() << " EnergyPoints.\n";
		a.attack("his brother");
        std::cout << a.getName() << " > "<< a.getHitPoints() << " Hp > " << a.getEnergyPoints() << " EnergyPoints.\n";

        std::cout << b.getName() << " > "<< b.getHitPoints() << " Hp > " << b.getEnergyPoints() << " EnergyPoints.\n";
		b.beRepaired(3);
        std::cout << b.getName() << " > "<< b.getHitPoints() << " Hp > " << b.getEnergyPoints() << " EnergyPoints.\n";
		for (int i = 0; i < 12; i++)
        {
            std::cout << "EnergyP > " << b.getEnergyPoints() << " ... ";
            b.attack("Trap");
            
        }
		b.beRepaired(3);
        std::cout << b.getName() << " has '"<< b.getHitPoints() << "' hit points and '" << b.getEnergyPoints() << "' energy points.\n";

		ClapTrap k(a);
		ClapTrap M;
		M = b;
		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
	}
    return 0;
}