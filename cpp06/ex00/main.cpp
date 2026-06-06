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

int main()
{

    return 0;
}

// int main() {
//     std::string str = "123.1    qq23kjgj.45.42lkslhg";
//     int x = 65;
//     std::cout << (int)x << " : x as an int"<< std::endl;
//     std::cout << x << " : x as a char"<< std::endl;
//     float x2 = x;
//     double x3 = x2;
//     std::cout << x2 << " : x as a float"<< std::endl;
//     std::cout << x3 << " : x as a double"<< std::endl;

//     std::cout << std::fixed << std::setprecision(2)
//               << static_cast<double>(x)
//               << "f" <<std::endl;

//     std::cout << std::fixed << std::setprecision(2)
//               << static_cast<float>(x)
//               << std::endl;

//     // For int
//     int int_val;
//     std::stringstream ss_int(str);
//     ss_int >> int_val; // int_val will be 123, extraction stops at the '.'

//     // For float
//     float float_val;
//     std::stringstream ss_float(str);
//     ss_float >> float_val; // float_val will be 123.45

//     // For double
//     double double_val;
//     std::stringstream ss_double(str);
//     ss_double >> double_val; // double_val will be 123.45

//     std::cout << "Int: " << int_val << std::endl;
//     std::cout << "Float: " << float_val << std::endl;
//     std::cout << "Double: " << double_val << std::endl;

//     // Error handling: check if the conversion was successful
//     if (ss_double.fail()) { // or ss_double.good() would return false
//         std::cerr << "Error: Conversion failed for double_val" << std::endl;
//     }
//     if (ss_float.fail()) { // or ss_double.good() would return false
//         std::cerr << "Error: Conversion failed for float_val" << std::endl;
//     }
//     if (ss_int.fail()) { // or ss_double.good() would return false
//         std::cerr << "Error: Conversion failed for int_val" << std::endl;
//     }
//     return 0;
// }
