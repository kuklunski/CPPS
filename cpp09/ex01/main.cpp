/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 09:22:45 by ylemkere          #+#    #+#             */
/*   Updated: 2026/04/24 09:22:45 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

static bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int main(int ac, char* av[])
{
    //
    int topElement = 0;
    int secElement = 0;
    std::stack<int> st;
    if (ac != 2)
    {
        std::cerr << "Wrong number of arguments" << std::endl;
        return 1;
    }
    std::string str = av[1];
    if (str.find_first_not_of("0123456789*/+- ") != std::string::npos)
    {
        std::cerr << "Input contains problematic chars" << std::endl;
        return 1;
    }
    int i = 0;
    for (; av[1][i]; i++)
    {
        if (std::isdigit(av[1][i]))
            st.push(av[1][i] - 48);

        if (isOperator(av[1][i]))
        {
            if (st.size() < 2)
            {
                std::cerr << "Incorrect input !" << std::endl;
                return 1;
            }

            topElement = st.top();
            st.pop();

            secElement = st.top();
            st.pop();

            if (av[1][i] == '+')
            {
                st.push(topElement + secElement);
            }
            else if (av[1][i] == '-')
            {
                st.push(secElement - topElement);
            }
            else if (av[1][i] == '*')
            {
                st.push(secElement * topElement);
            }
            else if (av[1][i] == '/')
            {   
                if (topElement == 0)
                {
                    std::cerr << "Division by 0 is forbidden !" << std::endl;
                    return 1;
                }
                st.push(secElement / topElement);
            }
        }
    }
    // debug

    std::stack<int> temp = st;
    while (!temp.empty())
    {
        if (temp.size() > 1)
        {
            std::cerr << "Error" << std::endl;
            return 1;
        }
        std::cout << "result = " << temp.top() << std::endl;
        temp.pop();
    }
    return 0;
}