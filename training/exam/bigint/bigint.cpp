#include "bigint.hpp"

bigint::bigint() : number("0")
{}
bigint::~bigint()
{}
bigint::bigint(unsigned int x)
{
    std::stringstream ss;
    ss << x;
    number = ss.str();
}
bigint::bigint(const bigint& other) : number(other.number)
{}

bigint& bigint::operator=(const bigint& other)
{
    if (this != &other)
    {
        number = other.number;
    }
    return *this;
}

std::string bigint::addition(std::string str1, std::string str2)
{
    int i = str1.length() - 1;
    int j = str2.length() - 1;
    int carry = 0;
    std::string result;

    while (i >= 0 || j >= 0 || carry)
    {
        int digit1 = (i >= 0) ? str1[i--] - '0' : 0;
        int digit2 = (j >= 0) ? str2[j--] - '0' : 0;
        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        result.insert(result.begin(), (sum % 10) + '0');
    }
    return result;
}

std::string bigint::get_number() const
{
    return number;
}

std::ostream& operator<<(std::ostream& os, const bigint& obj)
{
    os << obj.get_number();
    return os;
}

bigint& bigint::operator+=(const bigint& other)
{
    number = addition(number, other.number);
    return *this;
}

bigint bigint::operator+(const bigint& other) const
{
    bigint temp = *this;
    temp += other;
    return temp;
}

bigint& bigint::operator++()
{
    (*this) += bigint(1);
    return *this;
}

bigint bigint::operator++(int)
{
    bigint temp = (*this);
    (*this) += bigint(1);
    return temp;
}

bigint bigint::operator<<(unsigned int x) const
{
    bigint temp = (*this);

    if (temp.number == "0" || temp.number =="")
        return temp;
    while (x > 0)
    {
        temp.number.push_back('0');
        x--;
    }
    return temp;
}
bigint bigint::operator>>(unsigned int x) const
{
    bigint temp = (*this);

    if (x >= temp.number.length())
    {
        return bigint(0);
    }
    while (x > 0)
    {
        temp.number.erase(temp.number.length() - 1, 1);
        x--;
    }
    return temp;
}

bigint& bigint::operator<<=(unsigned int x)
{
    (*this) = (*this) << x;
    return *this;
}

bigint& bigint::operator>>=(unsigned int x)
{
    (*this) = (*this) >> x;
    return (*this);
}

bigint bigint::operator<<(const bigint& other) const
{
    std::stringstream ss(other.get_number());
    unsigned int x = 0;
    ss >> x;
    bigint temp = (*this);
    temp = temp << x;
    return temp;
}

bigint bigint::operator>>(const bigint& other) const
{
    std::stringstream ss(other.get_number());
    unsigned int x = 0;
    ss >> x;
    bigint temp = (*this);
    temp = temp >> x;
    return temp;
}
bigint& bigint::operator<<=(const bigint& other)
{
    std::stringstream ss(other.get_number());
    unsigned int x = 0;
    ss >> x;
    (*this) = (*this) << x;
    return *this;
}

bigint& bigint::operator>>=(const bigint& other)
{
    std::stringstream ss(other.get_number());
    unsigned int x = 0;
    ss >> x;
    (*this) = (*this) >> x;
    return *this;
}

bool bigint::operator==(const bigint& other) const
{
    std::string str1 = number;
    std::string str2 = other.get_number();
    if (str1 == str2)
        return true;
    else 
        return false;
}

bool bigint::operator!=(const bigint& other) const
{
    if (number != other.get_number())
        return true;
    else
        return false;
}

bool bigint::operator<(const bigint& other) const
{
    std::string str1 = number;
    std::string str2 = other.get_number();
    int len1 = str1.length();
    int len2 = str2.length();
    if (len1 != len2)
        return len1 < len2;
    else
        return str1 < str2;
}

bool bigint::operator>(const bigint& other) const
{
    return other < (*this);
}

bool bigint::operator<=(const bigint& other) const
{
    return (((*this) < other) || ((*this) == other));
}

bool bigint::operator>=(const bigint& other) const
{
    return (((*this) > other) || ((*this) == other));
}