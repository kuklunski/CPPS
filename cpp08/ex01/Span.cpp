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

Span::Span(unsigned int value) : N(value)
{
    std::cout << "Span constuctor with 'N'\n";
}

Span::Span(const Span& other) : N(other.N), span(other.span)
{
    std::cout << "Span copy constructor\n";
}

Span& Span::operator=(const Span& other)
{
    std::cout << "Span assignment operator\n";
    if (this != &other)
    {
        N = other.N;
        span = other.span;
    }
    return *this;
}

Span::~Span()
{
    std::cout << "Span destructor\n";
}

void Span::addNumber(int x)
{
    if (span.size() < N)
        span.push_back(x);
    else
        throw std::invalid_argument("span is full !!!");
}

int Span::shortestSpan()
{
    if (span.size() < 2)
        throw std::invalid_argument("span is of size < 2");

    std::vector<int> sorted(span);
    std::sort(sorted.begin(), sorted.end());

    std::vector<int> diffs(sorted.size());
    std::adjacent_difference(sorted.begin(), sorted.end(), diffs.begin());

    // diffs[0] is sorted[0] itself (no previous element), skip it
    return *std::min_element(diffs.begin() + 1, diffs.end());
}

int Span::longestSpan()
{
    if (span.size() < 2)
        throw std::invalid_argument("span is of size < 2");
    return *std::max_element(span.begin(), span.end())
         - *std::min_element(span.begin(), span.end());
}

void Span::print_vector()
{
    for (std::vector<int>::iterator it = span.begin(); it != span.end(); ++it)
        std::cout << *it << " ";
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
