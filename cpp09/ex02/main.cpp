/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 23:04:19 by ylemkere          #+#    #+#             */
/*   Updated: 2026/04/29 23:04:19 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// Binary search insert into a range [0, bound) bound is the winners position
void binaryInsertVector(std::vector<int>& chain, int val, int bound) 
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

void stepTwo(std::vector<int>& chain, std::vector<Pair>& pairs) 
{
    std::vector<int> order = jacobsthalOrderVector(pairs.size());

    for (size_t i = 0; i < order.size(); i++) 
    {
        // if at order{1, 5, 4, 3} for example and we arrive at 5
        // we need order[2] in idx to extract pairs[5 - 1(cause index based)].winner/loser
        int idx = order[i];
        int loser  = pairs[idx - 1].loser;
        int winner = pairs[idx - 1].winner;

        // here we need to insert the loser, we search for its winner using lowerbound
        // because a loser is guaranteed to be before its winner 
        // we extract chain.begin() to convert the pointer to an int value,
        // winner at index 10 for example would give bound = 10
        int bound = std::lower_bound(chain.begin(), chain.end(), winner) - chain.begin();

        // then we binaryInsert the loser at [0, bound] bound is the max
        // cause a loser cant be after its winner obviously
        binaryInsertVector(chain, loser, bound);
    }
}

// jo stands for jacobsthal order of course
// lets say i have this order jo = {0, 1, 1, 3, 5, 11, 21} and size = 6;
// result needs to be {1,  3,2,  5,4,   6}
// order starts at {1}
// we skip the first 0, and we insert 1 before the loop.
// so the starting index is i = 2
// to start here {0, 1, => '1'}
std::vector<int> jacobsthalOrderVector(int size)
{
    // base case checks
    if (size <= 0)
        return std::vector<int>();
    if (size == 1)
        return std::vector<int>(1, 1);

    // here i generate the sequence for size of pairs numbers
    // starting with the base initial jo order of {0, 1};
    std::vector<int> jo;
    jo.push_back(0);
    jo.push_back(1);
    while (jo.back() < size)
        jo.push_back(jo[jo.size() - 1] + 2 * jo[jo.size() - 2]);
    
    std::vector<int> order;
    order.push_back(1);
    int prev = 1;
    for (size_t i = 2; i < jo.size(); i++)
    {
        int curr = std::min(jo[i], size); // we need the min between index and kind of reverse jacobsthal order
        // so that we dont exceed the size of course, so the curr = min at max will give us the size of pairs
        // and if were not at the max yet it gives us a number from jo
        for (int j = curr; j > prev; j--)
        {
            order.push_back(j);
        }
        prev = curr;
        if (curr >= size)
            break ;

    }
    // std::cout << "{ ";
    // for (size_t k = 0; k < order.size(); k++)
    // {
    //     std::cout << order[k] << ",";
    // }
    // std::cout << " }" << std::endl;
    return order;
}

std::vector<int> fordJohnsonvector(std::vector<int> iV)
{
    int size = iV.size();
    int odd;

    if (size <= 1)
        return iV;

    std::vector<Pair> pairs;
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
    std::vector<int> winners;
    for (size_t i = 0; i < pairs.size(); i++) {
        winners.push_back(pairs[i].winner);
    }
    // for (size_t i = 0; i < winners.size(); i++) {
    //     std::cout << winners[i] << " ";
    // }
    // std::cout << std::endl;
    winners = fordJohnsonvector(winners);

    // // This call creates a NEW stack frame with its OWN pairs vector
    // std::vector<int> chain = fordJohnson(winners);
    
    // // When we get here, all deeper frames have already finished
    // // and this frame's `pairs` is still sitting here, untouched
    // stepTwo(chain, pairs);
    // return chain;
    stepTwo(winners, pairs);
    if (size % 2 != 0)
    {
        int bound = std::lower_bound(winners.begin(), winners.end(), odd) - winners.begin();
        binaryInsertVector(winners, odd, bound);
    }
    return winners;
}


int main (int ac, char* av[])
{
    if (ac < 2)
        return 0;

    struct timeval Vstart, Vend, Dstart, Dend;

    int i = 1;
    unsigned int number = 0;
    std::vector<int> iV; // initial vector
    std::deque<int> iD; // initial deque
    while (av[i])
    {
        std::string str = av[i];
        if (str.find_first_not_of("0123456789 ") != std::string::npos)
        {
            std::cerr << "Error in input" << std::endl;
            return 1;
        }
        std::stringstream sstream(av[i]);
        if (!(sstream >> number)) 
        {
            std::cerr << "Error: Input overflow or not an integer" << std::endl;
            return 1;
        }
        iV.push_back(number);
        iD.push_back(number);
        // std::vector<int>::iterator it = iV.begin();
        // for (it = iV.begin(); it != iV.end(); it++)
        // {
        //     std::cout << *it << " ";
        // }
        // std::cout << std::endl;
        // std::cout << str << "." << std::endl;
        // std::cout << "stream : " << number << "." << std::endl;
        i++;
    }
    std::cout << "Before : ";
    for (size_t it = 0; it < iV.size(); it++)
        std::cout << iV[it] << " ";
    std::cout << std::endl;

    gettimeofday(&Vstart, NULL);
    std::vector<int> result = fordJohnsonvector(iV);
    gettimeofday(&Vend, NULL);

    //std::vector<int> jo = jacobsthalOrderVector(13);
    std::cout << "After : ";
    for (size_t it = 0; it < result.size(); it++)
        std::cout << result[it] << " ";
    std::cout << std::endl;

    gettimeofday(&Dstart, NULL);
    std::deque<int> fD = fordJohnsonDeque(iD);
    gettimeofday(&Dend, NULL);

    //std::vector<int> jo = jacobsthalOrderVector(13);
    std::cout << "After : ";
    for (size_t it = 0; it < fD.size(); it++)
        std::cout << fD[it] << " ";
    std::cout << std::endl;
    
    

    // 1. Calculate raw differences first
    long Vseconds = Vend.tv_sec - Vstart.tv_sec;
    long Vuseconds = Vend.tv_usec - Vstart.tv_usec;
    long Dseconds = Dend.tv_sec - Dstart.tv_sec;
    long Duseconds = Dend.tv_usec - Dstart.tv_usec;

    // 2. Combine into a single microsecond double
    double vector_total_micros = (Vseconds * 1000000.0) + Vuseconds;
    double deque_total_micros = (Dseconds * 1000000.0) + Duseconds;
    // 3. Print with fixed precision
    std::cout << "Time to process using a vector ... : " 
            << std::fixed << std::setprecision(5) 
            << vector_total_micros << " us" << std::endl;

    std::cout << "Time to process using a Deque ... : " 
            << std::fixed << std::setprecision(5) 
            << deque_total_micros << " us" << std::endl;
    return 0;
}