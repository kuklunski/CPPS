#pragma once
#include <iostream>
#include <sstream>

class bigint
{
    private :
        std::string number;
    public :
        bigint();
        ~bigint();
        bigint(int x);
        bigint(const bigint& other);
        bigint& operator=(const bigint& other);
        friend std::ostream& operator<<(std::ostream &os, const bigint& object);
        std::string getstr() const;
        bigint& operator+=(const bigint& other);
        bigint& operator++();
        bigint operator++(int);
        bigint operator<<(int x);
        bigint operator>>(int x);
        bigint& operator<<=(int x);
        bigint& operator>>=(int x);
        bigint& operator>>=(const bigint& other);
        bool operator>(const bigint& right);
        bool operator<(const bigint& right);
        bool operator==(const bigint& other);
};

bigint operator+(bigint left, bigint right);
bigint operator+(bigint left, int x);
bigint operator+(int x, bigint left);

