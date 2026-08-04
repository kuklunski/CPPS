#pragma once

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
        bigint(unsigned int x);
        bigint(const bigint& other);
        bigint& operator=(const bigint& other);
        std::string addition(std::string str1, std::string str2);
        std::string get_number() const;
        bigint operator+(const bigint& other) const;
        bigint& operator+=(const bigint& other);
        bigint& operator++();
        bigint operator++(int);
        bigint operator<<(unsigned int x) const;
        bigint operator>>(unsigned int x) const;
        bigint& operator<<=(unsigned int x);
        bigint& operator>>=(unsigned int x);
        bigint operator<<(const bigint& other) const;
        bigint operator>>(const bigint& other) const;
        bigint& operator<<=(const bigint& other);
        bigint& operator>>=(const bigint& other);
        bool operator==(const bigint& other) const;
        bool operator!=(const bigint& other) const;
        bool operator<(const bigint& other) const;
        bool operator>(const bigint& other) const;
        bool operator<=(const bigint& other) const;
        bool operator>=(const bigint& other) const;
};

std::ostream& operator<<(std::ostream& os, const bigint& obj);