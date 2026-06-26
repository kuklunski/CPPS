#include "vect2.hpp"

vect2::vect2() : vect(2, 0)
{
}
vect2::vect2(int x, int y)
{
    vect.push_back(x);
    vect.push_back(y);
}
        
vect2::~vect2()
{
}

vect2::vect2(const vect2& origin)
{
    this->vect = origin.vect;
}
vect2& vect2::operator=(const vect2& origin)
{
    if (this != &origin)
    {
        this->vect = origin.vect;
    }
    return *this;
}
//std::cout << "{" << v[0] << ", " << v[1] << "}" << std::endl;
std::ostream& operator<<(std::ostream &os, const vect2& obj)
{
    // Make sure to use [0] and [1] to pull the individual numbers out!
    os << "{" << obj.vect[0] << ", " << obj.vect[1] << "}";
    

    return os;
}

int& vect2::operator[](size_t index) 
{
    return vect[index];
}

const int& vect2::operator[](size_t index) const
{
    return vect[index];
}

vect2& vect2::operator++()
{
    this->vect[0]++;
    this->vect[1]++;
    return *this;
}

vect2 vect2::operator++(int)
{
    vect2 temp = *this;
    this->vect[0]++;
    this->vect[1]++;
    return temp;
}

vect2& vect2::operator--()
{
    this->vect[0]--;
    this->vect[1]--;
    return *this;
}

vect2 vect2::operator--(int)
{
    vect2 temp = *this;
    this->vect[0]--;
    this->vect[1]--;
    return temp;
}

vect2& vect2::operator+=(const vect2& other)
{
    this->vect[0] += other.vect[0];
    this->vect[1] += other.vect[1];
    return *this;
}
vect2& vect2::operator-=(const vect2& other)
{
    this->vect[0] -= other.vect[0];
    this->vect[1] -= other.vect[1];
    return *this;
}

vect2& vect2::operator*=(int scalar)
{
    this->vect[0] *= scalar;
    this->vect[1] *= scalar;
    return *this;
}

vect2 operator+(vect2 left, vect2 right)
{
    left += right;
    return left;
}

vect2 operator-(vect2 left, vect2 right)
{
    left -= right;
    return left;
}

vect2 operator*(vect2 left, int scalar)
{
    left *= scalar;
    return left;
}

vect2 operator*(int scalar, vect2 right)
{
    right *= scalar;
    return right;
}

vect2 operator-(vect2 left)
{
    vect2 result = left;
    result *= -1;
    return result;
}

bool operator==(vect2 left, vect2 right)
{
    if ((left.vect[0] ==  right.vect[0] )&& (left.vect[1] == right.vect[1]))
        return true;
    else
        return false;
}


bool operator!=(vect2 left, vect2 right)
{
    if ((left.vect[0] ==  right.vect[0] ) && (left.vect[1] == right.vect[1]))
        return false;
    else
        return true;
}

