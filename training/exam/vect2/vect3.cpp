#include "vect3.hpp"

vect2::vect2()
{
    vect.push_back(0);
    vect.push_back(0);
}
vect2::vect2(int x, int y)
{
    vect.push_back(x);
    vect.push_back(y);
}
vect2::~vect2()
{

}
vect2::vect2(const vect2& other)
{
    this->vect = other.vect;
}
vect2& vect2::operator=(const vect2& other)
{
    this->vect = other.vect;
    return *this;
}

int vect2::operator[](size_t index) const
{
    return vect[index];
}

int& vect2::operator[](size_t index)
{
    return vect[index];
}

std::ostream& operator<<(std::ostream& os, const vect2& obj)
{
    os << "{" << obj.vect[0] << ", " << obj.vect[1] << "}";
    return os;
}

// ++v3
vect2& vect2::operator++()
{
    this->vect[0]++;
    this->vect[1]++;
    return *this;
}
// v3++
vect2 vect2::operator++(int)
{
    vect2 temp = *this;
    this->vect[0]++;
    this->vect[1]++;
    return temp;
}

// --3
vect2& vect2::operator--()
{
    this->vect[0]--;
    this->vect[1]--;
    return *this;
}
// v3--
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

bool vect2::operator==(const vect2& other)
{
    if (vect[0] != other.vect[0])
        return false;
    if (vect[1] != other.vect[1])
        return false;
    return true;
}
bool vect2::operator!=(const vect2& other)
{
    if (vect[0] != other.vect[0])
        return true;
    if (vect[1] != other.vect[1])
        return true;
    return false;
}