/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 23:04:44 by ylemkere          #+#    #+#             */
/*   Updated: 2026/04/29 23:04:44 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <deque>
#include <ctime>
#include <sys/time.h>
#include <iomanip>

struct Pair
{
    int winner;
    int loser;
};

std::vector<int> jacobsthalOrderVector(int size);
std::vector<int> fordJohnsonvector(std::vector<int> iV);
void stepTwo(std::vector<int>& chain, std::vector<Pair>& pairs);
void binaryInsertVector(std::vector<int>& chain, int val, int bound);

std::deque<int> fordJohnsonDeque(std::deque<int> iV);
std::deque<int> jacobsthalOrderDeque(int size);
void stepTwoDeque(std::deque<int>& chain, std::deque<Pair>& pairs);
void binaryInsertDeque(std::deque<int>& chain, int val, int bound);

long long getMicroTime();

#endif