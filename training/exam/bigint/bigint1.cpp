#include "bigint1.hpp"

bigint::bigint() : number("0")
{
}

bigint::bigint(int x)
{
    std::stringstream ss;
    ss << x;
    this->number = ss.str();
}

bigint::~bigint()
{
}

bigint::bigint(const bigint& other)
{
    this->number = other.number;
}

bigint& bigint::operator=(const bigint& other)
{
    this->number = other.number;
    return *this;
}

std::string bigint::getstr() const
{
    return this->number;
}

std::ostream& operator<<(std::ostream &os, const bigint& object)
{
    os << object.number;
    return os;
}

std::string addition(std::string str1, std::string str2)
{
    std::string result;
    int i = str1.size() - 1;
    int j = str2.size() - 1;
    int carry = 0;
    while (i >= 0 || j >= 0 || carry > 0)
    {
        int digit1 = (i >= 0) ? str1[i--] - '0' : 0;
        int digit2 = (j >= 0) ? str2[j--] - '0' : 0;
        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        result.insert(result.begin(), (sum % 10) + '0');
    }
    return result;
}

bigint& bigint::operator+=(const bigint& other)
{
    this->number = addition(this->number, other.number);
    return *this;
}

bigint operator+(bigint left, bigint right)
{
    left += right;
    return left;
}

bigint operator+(bigint left, int x)
{
    bigint temp(x);
    left += temp;
    return left;
}

bigint operator+(int x, bigint left)
{
    bigint temp(x);
    left += temp;
    return left;
}

bigint bigint::operator++(int)
{
    bigint temp = *this;
    *this += bigint(1);
    return temp;
}

bigint& bigint::operator++()
{
    *this += bigint(1);
    return *this;
}

bigint bigint::operator<<(int x)
{
    bigint temp = *this;
    while (x > 0)
    {
        temp.number.push_back('0');
        x--;
    }
    return temp;
}
bigint bigint::operator>>(int x)
{
    bigint temp = *this;
    while (x > 0)
    {
        temp.number.erase(temp.number.size() - 1, 1);
        x--;
    }
    return temp;
}
bigint& bigint::operator<<=(int x)
{
    while(x > 0)
    {
        this->number.push_back('0');
        x--;
    }
    return *this;
}

bigint& bigint::operator>>=(int x)
{
    while(x > 0)
    {
        this->number.erase(this->number.size() - 1, 1);
        x--;
    }
    return *this;
}

bigint& bigint::operator>>=(const bigint& other)
{
    std::string str = other.number;
    std::stringstream   ss(str);
    int i = 0;
    ss >> i;
    (*this) = (*this) >> i;
    return (*this);
}

bool bigint::operator>(const bigint& right)
{
    std::string str1 = this->getstr();
    std::string str2 = right.getstr();
    if (str1.size() > str2.size())
    {
        return true;
    }
    else if (str1.size() < str2.size())
    {
        return false;
    }
    else
    {
        return str1 > str2;
    }
}
bool bigint::operator==(const bigint& other)
{
    if (this->getstr() == other.getstr())
    {
        return true;
    }
    else
        return false;
}
bool bigint::operator<(const bigint& right)
{
    std::string str1 = this->getstr();
    std::string str2 = right.getstr();
    if (str1.size() < str2.size())
    {
        return true;
    }
    else if (str1.size() > str2.size())
    {
        return false;
    }
    else
    {
        return str1 < str2;
    }
}