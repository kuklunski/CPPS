/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 03:50:37 by ylemkere          #+#    #+#             */
/*   Updated: 2026/04/15 03:50:37 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
    Data data = {"yassir", 50, "male"};
    
    uintptr_t address = reinterpret_cast<uintptr_t>(&data);
    Data *ptr2 = reinterpret_cast<Data*>(address);

    std::cout << "---- Data inside uintptr_t 'address' ----\n";
    std::cout << "name   -> " << ptr2->name << "\n";
    std::cout << "age    -> " << ptr2->age << "\n";
    std::cout << "gender -> " << ptr2->gender << "\n";
    
/////////////////////////////////////////////////////////////////
    uintptr_t t;
    Data *ptr = &data;

    std::cout << "before Seri ==> ptr = " << ptr << std::endl;
    t = Serializer::serialize(ptr);

    std::cout << "Serialize ====> t   = " << t << std::endl;
    ptr = Serializer::deserialize(t);
    std::cout << "Deserialize ==> ptr = " << ptr << std::endl;

    std::cout << "---- Data inside uintptr_t 't' ----\n";
    std::cout << "name   -> " << ptr->name << "\n";
    std::cout << "age    -> " << ptr->age << "\n";
    std::cout << "gender -> " << ptr->gender << "\n";
    return 0;
}