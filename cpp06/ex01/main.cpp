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

// no conversion, just relabeling
// 1 - it performs very dangerous type casting from a pointer to any other pointer of any type
// 2 - used to work on bits
// 3 - the result of reinterpret cast cannot be used for anything other than
// being casted back to the original type
// 4 - if we use this type of cast the program becomes non portable because of differences in architecture