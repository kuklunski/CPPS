/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 06:02:05 by ylemkere          #+#    #+#             */
/*   Updated: 2026/04/11 06:02:05 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// default constructor of vector<> already creates an empty vector
// so no need for : span() or span(0,0) for example
Span::Span() : N(0)
{
    std::cout << "Span def constuctor\n";
}

Span::~Span()
{
    std::cout << "Span destructor\n";
}

Span::Span(unsigned int value) : N(value)
{
    std::cout << "Span constuctor with 'N'\n";
}

void Span::addNumber(int x)
{
    if (span.size() < N)
    {
        span.push_back(x);
        _set.insert(x);
    }
    else
        throw std::invalid_argument("span is full !!!");
}

int Span::shortestSpan()
{
    if (_set.size() >= 2)
    {
        int min_dist = std::numeric_limits<int>::max();
        std::set<int>::iterator it = _set.begin();
        std::set<int>::iterator it_next = it;
        ++it_next;
        while (it_next != _set.end())
        {
            int diff = *it_next - *it;
            if (diff < min_dist)
                min_dist = diff;
            ++it;
            ++it_next;    
        }
        return min_dist;
    }
    else 
        throw std::invalid_argument("span is of size < 2");
}

int Span::longestSpan()
{
    if (_set.size() < 2)
        throw std::invalid_argument("span is of size < 2");
    else 
        return *_set.rbegin() - *_set.begin();
}

void Span::print_vector()
{
    for (std::set<int>::iterator it1 = _set.begin(); it1 != _set.end(); ++it1)
        std::cout << *it1 << " ";
    std::cout << std::endl;
}

void Span::addxNum(int N)
{
    std::srand(static_cast<unsigned int>(std::time(0)));
    int min = -5000;
    int max = 5000;
    int randomNum;
    int i = 0;
    while (i++ < N)
    {
        randomNum = std::rand() % (max - min + 1) + min;
        addNumber(randomNum);
    }
}