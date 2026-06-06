/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 05:56:48 by ylemkere          #+#    #+#             */
/*   Updated: 2026/04/11 05:56:48 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <limits>
#include <set>
#include <cstdlib>
#include <ctime> 
#include <algorithm>

class Span
{
    private :
        unsigned int N;
        std::vector<int> span;
        std::set<int> _set;
        
    public :
        Span();
        ~Span();
        Span(unsigned int value);
        //Span& operator=(const Span& other);
        //Span(const Span& other);
        void addNumber(int x);
        int shortestSpan();
        int longestSpan();
        void print_vector();
        void addxNum(int N);
};

#endif