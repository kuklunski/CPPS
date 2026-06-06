/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 23:04:41 by ylemkere          #+#    #+#             */
/*   Updated: 2026/04/29 23:04:41 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

long long getMicroTime()
{
    struct timeval tv;
    gettimeofday(&tv,NULL);
    return (long long)tv.tv_sec * 1000000 + tv.tv_usec;
}

void binaryInsertDeque(std::deque<int>& chain, int val, int bound) 
{
    int lo = 0, hi = bound;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (chain[mid] < val)
            lo = mid + 1;
        else
            hi = mid;
    }
    chain.insert(chain.begin() + lo, val);
}

void stepTwoDeque(std::deque<int>& chain, std::deque<Pair>& pairs) 
{
    std::deque<int> order = jacobsthalOrderDeque(pairs.size());

    for (size_t i = 0; i < order.size(); i++) 
    {
        int idx = order[i];
        int loser  = pairs[idx - 1].loser;
        int winner = pairs[idx - 1].winner;

        int bound = std::lower_bound(chain.begin(), chain.end(), winner) - chain.begin();

        binaryInsertDeque(chain, loser, bound);
    }
}

std::deque<int> jacobsthalOrderDeque(int size)
{
    // base case checks
    if (size <= 0)
        return std::deque<int>();
    if (size == 1)
        return std::deque<int>(1, 1);

    std::deque<int> jo;
    jo.push_back(0);
    jo.push_back(1);
    while (jo.back() < size)
        jo.push_back(jo[jo.size() - 1] + 2 * jo[jo.size() - 2]);
    
    std::deque<int> order;
    order.push_back(1);
    int prev = 1;
    for (size_t i = 2; i < jo.size(); i++)
    {
        int curr = std::min(jo[i], size);
        for (int j = curr; j > prev; j--)
        {
            order.push_back(j);
        }
        prev = curr;
        if (curr >= size)
            break ;

    }
    return order;
}

std::deque<int> fordJohnsonDeque(std::deque<int> iV)
{
    int size = iV.size();
    int odd;

    if (size <= 1)
        return iV;

    std::deque<Pair> pairs;
    for (int i = 0; i + 1 < size; i = i + 2)
    {
        Pair p;
        if (iV[i] > iV[i + 1]) 
        {
            p.winner = iV[i];
            p.loser = iV[i + 1];
        } 
        else 
        {
            p.winner = iV[i + 1];
            p.loser = iV[i];
        }
        pairs.push_back(p);
    }

    if (size % 2 != 0)
    {
        odd = iV[size - 1];
    }
    else 
        odd = 0;
    (void)odd;
    std::deque<int> winners;
    for (size_t i = 0; i < pairs.size(); i++) {
        winners.push_back(pairs[i].winner);
    }

    winners = fordJohnsonDeque(winners);

    stepTwoDeque(winners, pairs);
    // insert the odd element
    if (size % 2 != 0)
    {
        int bound = std::lower_bound(winners.begin(), winners.end(), odd) - winners.begin();
        binaryInsertDeque(winners, odd, bound);
    }
    return winners;
}
