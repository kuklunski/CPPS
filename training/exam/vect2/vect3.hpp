#pragma once

#include <vector>
#include <iostream>

class vect2
{
    private :
        std::vector<int> vect;
    public :
        vect2();
        vect2(int x, int y);
        ~vect2();
        vect2(const vect2& other);
        vect2& operator=(const vect2& other);
        int operator[](size_t index) const;
        int& operator[](size_t index);
        friend std::ostream& operator<<(std::ostream& os, const vect2& obj);
        vect2& operator++();
        vect2 operator++(int);
        vect2& operator--();
        vect2 operator--(int);
        vect2& operator+=(const vect2& other);
        vect2& operator-=(const vect2& other);
        vect2& operator*=(int scalar);
        bool operator==(const vect2& other);
        bool operator!=(const vect2& other);
};

vect2 operator+(vect2 left, vect2 right);
vect2 operator-(vect2 left, vect2 right);
vect2 operator*(vect2 left, int scalar);
vect2 operator*(int scalar, vect2 right);
vect2 operator-(vect2 left);