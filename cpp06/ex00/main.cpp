/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 22:20:36 by ylemkere          #+#    #+#             */
/*   Updated: 2026/02/26 22:20:36 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./convert <literal>" << std::endl;
		return 1;
	}
	ScalarConverter::convert(argv[1]);
	return 0;
}

// real, compile-time conversion
// the compiler emits actual CPU instructions to convert the bit representation
// from int to float for example 
// 1 - it performs compatible conversions, just like C casting, better for readability
// 	like from int to float
// 2 - static_cast stops unrelated pointer conversions and is more restrictive than C cast
//  example : char * => int * is allowed in C it will compile and fail at runtime
//  but not in static_cast, it will fail at compile time
// 3 - use for upcasts, never for downcasts
//  casting from derived to base to another derived(like a triangle) dangerous