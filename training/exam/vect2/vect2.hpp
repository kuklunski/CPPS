#pragma once

#include <iostream>

class vect2
{
    private :
        int x;
        int y;
    public :
        vect2();
        vect2(int a, int b);
        ~vect2();
        vect2(const vect2& other);
        vect2& operator=(const vect2& other);
        int getx() const;
        int gety() const;
        int& operator[](int index);
        const int& operator[](int index) const;

        vect2& operator++();
        vect2& operator--();
        vect2 operator++(int);
        vect2 operator--(int);

        vect2& operator+=(const vect2& other);
        vect2& operator-=(const vect2& other);
        vect2& operator*=(int ratio);
        vect2 operator*(int ratio) const;
        vect2 operator+(const vect2& other) const;
        vect2 operator-(const vect2& other) const;

        vect2 operator+();
        vect2 operator-();


        bool operator==(const vect2& other) const;
        bool operator!=(const vect2& other) const;
};

std::ostream& operator<<(std::ostream& os, const vect2& obj);
vect2 operator*(int ratio, const vect2& obj);