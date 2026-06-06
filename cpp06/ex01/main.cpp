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
    Data data;
    Data *ptr = &data;
    ptr->name = "yassir";
    ptr->age = 100;
    ptr->gender = "male";
    uintptr_t t;
    std::cout << "before Seri ==> ptr = " << ptr << std::endl;
    t = Serializer::serialize(ptr);
    std::cout << "Serialize ====> t   = " << t << std::endl;
    ptr = Serializer::deserialize(t);
    std::cout << "Deserialize ==> ptr = " << ptr << std::endl;
    return 0;
}