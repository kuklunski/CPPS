#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <string>
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
        std::string getstr() const;
        friend std::ostream& operator<<(std::ostream& os, const bigint& obj);
        bigint& operator+=(const bigint& other);
        std::string addition(std::string str1, std::string str2);
        bigint& operator++();
        bigint operator++(int);
        bigint operator>>(int x);
        bigint operator<<(int x);
        bigint& operator>>=(int x);
        bigint& operator<<=(int x);
        bigint& operator>>=(const bigint& other);
        bigint& operator<<=(const bigint& other);
        bool operator>(const bigint& other) const;
        bool operator<(const bigint& other) const;
        bool operator==(const bigint& other) const;
        bool operator!=(const bigint& other) const;
        bool operator>=(const bigint& other) const;
        bool operator<=(const bigint& other) const;
};

bigint operator+(bigint left, int x);
bigint operator+(bigint left, bigint right);
bigint operator+(int x, bigint right);
#endif