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
#include "ScavTrap.hpp"

int main(int ac, char **av)
{
	std::string arg = "";
	if (ac > 1)
		arg = av[1];
	if (arg == "ClapTrap" && ac > 1)
	{
		std::string arg = av[1];
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
		std::cout << a.getMaxHp() << " <<>> "<< b.getMaxHp() << "\n";
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

	if (arg == "ScavTrap" && ac > 1)
	{
		std::cout << "### TESTING ScavTrap ###\n" << std::endl;
	{
		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		ScavTrap a;
		ScavTrap b("B >>");

		std::cout << "\033[34mTesting\033[0m" << std::endl;
		a.attack("his brother");
        std::cout << a.getName() << " > "<< a.getHitPoints() << " Hp > " << a.getEnergyPoints() << " EnergyPoints.\n";
		a.takeDamage(35);
        std::cout << a.getName() << " > "<< a.getHitPoints() << " Hp > " << a.getEnergyPoints() << " EnergyPoints.\n";
		a.takeDamage(25);
        std::cout << a.getName() << " > "<< a.getHitPoints() << " Hp > " << a.getEnergyPoints() << " EnergyPoints.\n";
		a.beRepaired(49);
        std::cout << a.getName() << " > "<< a.getHitPoints() << " Hp > " << a.getEnergyPoints() << " EnergyPoints.\n";
		a.attack("his brother");
        std::cout << a.getName() << " > "<< a.getHitPoints() << " Hp > " << a.getEnergyPoints() << " EnergyPoints.\n";

        std::cout << b.getName() << " > "<< b.getHitPoints() << " Hp > " << b.getEnergyPoints() << " EnergyPoints.\n";
		b.beRepaired(9);
		b.takeDamage(40);
		b.beRepaired(38);
        std::cout << b.getName() << " > "<< b.getHitPoints() << " Hp > " << b.getEnergyPoints() << " EnergyPoints.\n";
		for (int i = 0; i < 12; i++)
        {
            std::cout << "EnergyP > " << b.getEnergyPoints() << " ... ";
            b.attack("Trap");
            
        }
		b.beRepaired(3);
        std::cout << b.getName() << " has '"<< b.getHitPoints() << "' hit points and '" << b.getEnergyPoints() << "' energy points.\n";

		ScavTrap k(a);
		ScavTrap M;
		M = b;
		b.gateMode();
		b.gateMode();
		b.gateMode();
		b.gateMode();
		b.gateMode();
		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
	}
	}
    return 0;
}