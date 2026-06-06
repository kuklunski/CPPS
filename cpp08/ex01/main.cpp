/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 06:24:23 by ylemkere          #+#    #+#             */
/*   Updated: 2026/04/11 06:24:23 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
// for purely test/debugg reasons


int main ()
{
    // generate a random number between 1 - 100
    Span v(100);
    v.addxNum(100);
    v.print_vector();
    std::cout << "longest span : " << v.longestSpan() << std::endl;
    std::cout << "shortest span : " << v.shortestSpan() << std::endl;
}