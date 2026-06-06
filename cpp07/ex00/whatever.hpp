/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 01:27:41 by ylemkere          #+#    #+#             */
/*   Updated: 2026/04/03 01:27:41 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>
#include <string>


template <typename T> T max(T x, T y){
    return (x > y) ? x : y;
}

template <typename T> T min(T x, T y){
    return (x < y) ? x : y;
}

template <typename T> void swap(T &x, T &y){
    T temp;
    temp = x;
    x = y;
    y = temp;
}

#endif