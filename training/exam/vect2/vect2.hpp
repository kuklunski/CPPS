#ifndef VECT2_HPP
#define VECT2_HPP

#include <vector>
#include <iostream>

class vect2 {
    private :
        std::vector<int> vect;
    public :
        vect2();
        vect2(int x, int y);
        ~vect2();
        vect2(const vect2& origin);
        vect2 &operator=(const vect2& origin);
        friend std::ostream& operator<<(std::ostream &os, const vect2& obj);
        int& operator[](size_t index);
        const int& operator[](size_t index) const;
        // v++ operator, takes int returns an obj
        vect2 operator++(int);
        vect2& operator++();
        vect2 operator--(int);
        vect2& operator--();
        vect2& operator+=(const vect2& other);
        vect2& operator-=(const vect2& other);
        vect2& operator*=(int scalar);
        friend bool operator==(vect2 left, vect2 right);
        friend bool operator!=(vect2 left, vect2 right);
    };
vect2 operator+(vect2 left, vect2 right);
vect2 operator-(vect2 left, vect2 right);
vect2 operator*(vect2 left, int scalar);
vect2 operator*(int scalar, vect2 right);
vect2 operator-(vect2 left);


#endif