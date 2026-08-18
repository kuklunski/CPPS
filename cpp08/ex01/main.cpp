/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 06:24:23 by ylemkere          #+#    #+#             */
/*   Updated: 2026/04/11 06:24:23 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
// for purely test/debugg reasons

int main ()
{
    // generate a random number between 1 - 100
    Span v(100);
    v.addxNum(100);
    v.print_vector();
    std::cout << "longest span : " << v.longestSpan() << std::endl;
    std::cout << "shortest span : " << v.shortestSpan() << std::endl;

    // subject-style small example
    Span sp(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << "small span shortest : " << sp.shortestSpan() << std::endl;
    std::cout << "small span longest : " << sp.longestSpan() << std::endl;

    // bulk add via iterator range, instead of calling addNumber() one by one
    std::vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    Span bulk(10);
    bulk.addNumber(nums.begin(), nums.end());
    bulk.print_vector();

    // duplicate values must yield a shortest span of 0
    Span dup(4);
    dup.addNumber(5);
    dup.addNumber(5);
    dup.addNumber(10);
    dup.addNumber(20);
    std::cout << "duplicate shortest span (expect 0) : " << dup.shortestSpan() << std::endl;

    // copy constructor / assignment operator
    Span copy(sp);
    std::cout << "copy shortest span : " << copy.shortestSpan() << std::endl;
    Span assigned;
    assigned = sp;
    std::cout << "assigned shortest span : " << assigned.shortestSpan() << std::endl;

    // exceptions: too many numbers, or not enough numbers for a span
    try {
        Span full(2);
        full.addNumber(nums.begin(), nums.end());
    }
    catch (const std::exception &e) {
        std::cout << "caught exception : " << e.what() << std::endl;
    }
    try {
        Span empty(2);
        empty.addNumber(1);
        empty.shortestSpan();
    }
    catch (const std::exception &e) {
        std::cout << "caught exception : " << e.what() << std::endl;
    }

    return 0;
}
