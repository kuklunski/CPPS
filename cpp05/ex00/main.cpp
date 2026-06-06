/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 18:34:35 by ylemkere          #+#    #+#             */
/*   Updated: 2026/02/14 18:34:35 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"

int main ()
{
    Bureaucrat b1;
    std::cout << b1;
    try {
        Bureaucrat a("Bob", 10);
        Bureaucrat b("Alice", 151);   // this will throw
        Bureaucrat c("Tom", 20);    // never reached
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 1;
}