/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 01:57:53 by ylemkere          #+#    #+#             */
/*   Updated: 2026/04/11 01:57:53 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <stdexcept>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>

template <typename T>
typename T::iterator easyfind (T& v, int x)
{
    typename T::iterator it = std::find(v.begin(), v.end(), x);
    if (it != v.end())
        return it;
    else
        throw std::invalid_argument("Value not found");
}

#endif