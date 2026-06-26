#include "bigint.hpp"

bigint::~bigint()
{

}

bigint::bigint() : number("0")
{
}

bigint::bigint(int x)
{
    std::stringstream ss;
    ss << x;
    this->number = ss.str();
    // std::cout << "number : "<< number << std::endl;
}

bigint::bigint(const bigint& other)
{
    this->number = other.number;
}

bigint& bigint::operator=(const bigint& other)
{
    number = other.number;
    return *this;
}

std::ostream& operator<<(std::ostream& os,const bigint& obj)
{
    os << obj.number;
    return os;
}

std::string bigint::getstr() const
{
    return this->number;
}

//   "1337"
// + "9999"
std::string bigint::addition(std::string str1, std::string str2)
{
    std::string result;
    int carry = 0;
    int i = str1.length() - 1;
    int j = str2.length() - 1;

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

bigint& bigint::operator+=(const bigint& other)
{
    this->number = addition(this->number, other.number);
    return *this;
}

bigint& bigint::operator++()
{
    this->number = addition(this->number, "1");
    return *this;
}

bigint bigint::operator++(int)
{
    bigint temp = *this;
    this->number = addition(this->number, "1");
    return temp;
}

bigint bigint::operator>>(int x)
{
    bigint temp = *this;
    while(x > 0)
    {  
        temp.number.erase(temp.number.length() - 1, 1);
        x--;
    }
    return temp;
}

bigint bigint::operator<<(int x)
{
    bigint temp = *this;
    while(x > 0)
    {  
        temp.number.push_back('0');
        x--;
    }
    return temp;
}

bigint operator+(bigint left, int x)
{
    bigint temp(x);
    left += temp;
    return left;
}
bigint operator+(bigint left, bigint right)
{
    left += right;
    return left;
}
bigint operator+(int x, bigint right)
{
    bigint temp(x);
    right += temp;
    return right;
}

bigint& bigint::operator>>=(int x)
{
    (*this) = (*this) >> x;
    return *this;
}

bigint& bigint::operator<<=(int x)
{
    (*this) = (*this) << x;
    return *this;
}

bigint& bigint::operator<<=(const bigint& other)
{
    int i = 0;
    std::string str = other.getstr();
    std::stringstream ss(str);
    ss >> i;
    (*this) = (*this) << i;
    return *this;
}

bigint& bigint::operator>>=(const bigint& other)
{
    int i = 0;
    std::string str = other.getstr();
    std::stringstream ss(str);
    ss >> i;
    (*this) = (*this) >> i;
    return *this;
}

bool bigint::operator>(const bigint& other) const
{
    std::string number1 = this->getstr();
    std::string number2 = other.getstr();

    int length1 = number1.length();
    int length2 = number2.length();

    if (length1 > length2)
        return true;
    else if (length1 < length2)
        return false;
    else {
        for (int i = 0; i < length1; i++)
        {
            if (number1[i] != number2[i])
                return number1[i] > number2[i];
        }
        return false;
    }
}

bool bigint::operator<(const bigint& other) const
{
    return other > *this;
}

bool bigint::operator==(const bigint& other) const
{
    if (this->getstr() == other.getstr())
        return true;
    else
        return false;
}

bool bigint::operator!=(const bigint& other) const
{
    if (this->getstr() != other.getstr())
        return true;
    else
        return false;
}

bool bigint::operator>=(const bigint& other) const
{
    if ((*this < other) == true)
        return false;
    return true;
}
bool bigint::operator<=(const bigint& other) const
{
    if ((*this) > other == true)
        return false;
    return true;
}