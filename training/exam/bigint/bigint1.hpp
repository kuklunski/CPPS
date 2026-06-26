#pragma once

#include <iostream>
#include <string>
#include <sstream>

class bigint
{
    private:
        std::string str;
    public :
        bigint();
        bigint(int x);
        ~bigint();
        bigint(const bigint& other);
        std::string getstr() const;
        bigint& operator=(const bigint& other);
        friend std::ostream& operator<<(std::ostream& os, const bigint& obj);
        bigint& operator+=(const bigint& other);
        std::string addition(std::string left, std::string right);
        bigint& operator++();
        bigint operator++(int);
        bigint operator<<(int x);
        bigint operator>>(int x);
        bigint& operator>>=(int x);
        bigint& operator<<=(int x);
        bigint& operator>>=(const bigint& obj);
        bool operator<(const bigint& other);
        bool operator>(const bigint& other);
        bool operator==(const bigint& other);
        bool operator!=(const bigint& other);
        bool operator>=(const bigint& other);
};

bigint operator+(bigint left, bigint right);
bigint operator+(bigint left, int x);
bigint operator+(int x, bigint right);
