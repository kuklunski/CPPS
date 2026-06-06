/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 01:46:12 by ylemkere          #+#    #+#             */
/*   Updated: 2026/04/03 01:46:12 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

    // T howa type : example  int[] or string[], * for address
template <typename T, typename F> void iter(T *array, const size_t length, F func)
{
    if (!array)
        return ;
    for (size_t i = 0; i < length; i++)
        func(array[i]);
    return ;
}

#endif