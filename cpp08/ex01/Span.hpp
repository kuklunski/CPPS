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
#include <algorithm>
#include <numeric>
#include <iterator>
#include <stdexcept>
#include <cstdlib>
#include <ctime>

class Span
{
    private :
        unsigned int N;
        std::vector<int> span;

    public :
        Span();
        Span(unsigned int value);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        void addNumber(int x);

        template <typename InputIterator>
        void addNumber(InputIterator first, InputIterator last)
        {
            if (span.size() + static_cast<size_t>(std::distance(first, last)) > N)
                throw std::invalid_argument("span is full !!!");
            span.insert(span.end(), first, last);
        }

        int shortestSpan();
        int longestSpan();
        void print_vector();
        void addxNum(int N);
};

#endif
