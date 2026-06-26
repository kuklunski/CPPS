#include "bigint1.hpp"

bigint::bigint() : str("0")
{
}
bigint::bigint(int x)
{
    std::stringstream ss;
    ss << x;
    str = ss.str();
}
bigint::~bigint()
{ 
}
bigint::bigint(const bigint& other)
{
    str = other.str;
}
bigint& bigint::operator=(const bigint& other)
{
    str = other.str;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const bigint& obj)
{
    os << obj.str;
    return os;
}

std::string bigint::getstr() const
{
    return str;
}
// "1444546"
// "1564569"
std::string bigint::addition(std::string left, std::string right)
{
    int carry = 0;
    std::string result;
    int i = left.length() - 1;
    int j = right.length() - 1;
    while (i >= 0 || j >= 0 || carry != 0)
    {
        int digit1 = (i >= 0) ? left[i--] - '0' : 0;
        int digit2 = (j >= 0) ? right[j--] - '0' : 0;
        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        result.insert(result.begin(), (sum % 10) + '0');
    }
    return result;
}

bigint& bigint::operator+=(const bigint& other)
{
    str = addition(str, other.getstr());
    return *this;
}

bigint operator+(bigint left, bigint right)
{
    bigint temp(left);
    temp += right;
    return temp;
}
bigint operator+(bigint left, int x)
{
    bigint temp(x);
    temp += left;
    return temp;
}
bigint operator+(int x, bigint right)
{
    bigint temp(x);
    temp += right;
    return temp;
}

bigint& bigint::operator++()
{
    bigint temp(1);
    (*this) += temp;
    return *this;
}

bigint bigint::operator++(int)
{
    bigint temp = (*this);
    (*this) += bigint(1);
    return temp;
}

bigint bigint::operator<<(int x)
{
    bigint temp = *this;
    while (x > 0)
    {
        temp.str.push_back('0');
        x--;
    }
    return temp;
}

bigint bigint::operator>>(int x)
{
    bigint temp = *this;
    while (x > 0)
    {
        temp.str.erase(temp.str.length() - 1, 1);
        x--;
    }
    return temp;
}

bigint& bigint::operator<<=(int x)
{
    while (x > 0)
    {
        str.push_back('0');
        x--;
    }
    return *this;
}

bigint& bigint::operator>>=(int x)
{
    while (x > 0)
    {
        str.erase(str.length() - 1, 1);
        x--;
    }
    return *this;
}

bigint& bigint::operator>>=(const bigint& obj)
{
    int x = 0;
    std::stringstream ss(obj.getstr());
    ss >> x;
    (*this) = (*this) >> x;
    return *this;
}

// std::cout << "(d < a) = " << (d < a) << std::endl;
bool bigint::operator<(const bigint& other)
{
    if (this->getstr().length() < other.getstr().length())
        return true;
    if (this->getstr().length() > other.getstr().length())
        return false; 
    if (this->getstr() > other.getstr())
        return true;
    else
        return false;
}

bool bigint::operator>(const bigint& other)
{
    if (this->getstr().length() > other.getstr().length())
        return true;
    if (this->getstr().length() < other.getstr().length())
        return false; 
    if (this->getstr() < other.getstr())
        return true;
    else
        return false;
}

bool bigint::operator==(const bigint& other)
{
    if (this->getstr() == other.getstr())
        return true;
    return false;
}

bool bigint::operator!=(const bigint& other)
{
    if (this->getstr() == other.getstr())
        return false;
    return true;
}

bool bigint::operator>=(const bigint& other)
{
    if ((*this > other) == true || (*this == other) == true)
        return true;
    return false;
}