#include "vect2.hpp"

vect2::vect2() : x(0), y(0)
{}

vect2::vect2(int a, int b) : x(a), y(b)
{}

vect2::~vect2() {}
        
vect2::vect2(const vect2& other) : x(other.x), y(other.y)
{}

vect2& vect2::operator=(const vect2& other)
{
    if (this != &other)
    {
        x = other.x;
        y = other.y;
    }
    return *this;
}

int vect2::getx() const
{
    return x;
}

int vect2::gety() const
{
    return y;
}

//std::cout << "{" << v[0] << ", " << v[1] << "}" << std::endl;
std::ostream& operator<<(std::ostream &os, const vect2& obj)
{
    os << "{" << obj.getx() << ", " << obj.gety() << "}";
    return os; 
}

int& vect2::operator[](int index)
{
    if (index == 0)
        return x;
    else
        return y;
}

const int& vect2::operator[](int index) const
{
    if (index == 0)
        return x;
    else
        return y;
}


vect2& vect2::operator++()
{
    x++;
    y++;
    return *this;
}

vect2& vect2::operator--()
{
    x--;
    y--;
    return *this;
}

vect2 vect2::operator++(int)
{
    vect2 temp = *this;
    x++;
    y++;
    return temp;
}

vect2 vect2::operator--(int)
{
    vect2 temp = *this;
    x--;
    y--;
    return temp;
}

vect2 vect2::operator+(const vect2& other) const
{
    return (vect2(x + other.x, y + other.y));
}
vect2 vect2::operator-(const vect2& other) const
{
    return (vect2(x - other.x, y - other.y));
}
vect2 vect2::operator+()
{
    return (vect2(+x, +y));
}
vect2 vect2::operator-()
{
    return (vect2(-x, -y));
}

vect2& vect2::operator+=(const vect2& other)
{
    x = x + other.x;
    y = y + other.y;
    return *this;
}
vect2& vect2::operator-=(const vect2& other)
{
    x = x - other.x;
    y = y - other.y;
    return *this;
}

vect2& vect2::operator*=(int ratio)
{
    x = x * ratio;
    y = y * ratio;
    return *this;
}

vect2 vect2::operator*(int ratio) const
{
    return (vect2(x * ratio, y * ratio));
}

vect2 operator*(int ratio, const vect2& obj)
{
    return (vect2(obj.getx() * ratio, obj.gety() * ratio));
}

bool vect2::operator==(const vect2& other) const
{
    if (x == other.x && y == other.y)
        return true;
    else
        return false;
}

bool vect2::operator!=(const vect2& other) const
{
    if (x == other.x && y == other.y)
        return false;
    else
        return true;
}
