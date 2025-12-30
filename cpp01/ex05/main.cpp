/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 00:12:45 by ylemkere          #+#    #+#             */
/*   Updated: 2025/12/09 00:12:45 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main (void)
{
    Harl harl;

	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
    harl.complain("1ERROR");
	harl.complain("A");
    harl.complain("A");
    harl.complain("A");
    harl.complain("A");
    harl.complain("A");
    return 0;
}
