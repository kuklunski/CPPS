/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 22:01:10 by ylemkere          #+#    #+#             */
/*   Updated: 2026/03/02 22:01:10 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <cstdlib>
#include <algorithm>

template <typename T> class Array
{
    private :
        T *data;
        unsigned int _size;
    public :
        Array<T>();
        Array<T>(unsigned int value);
        ~Array<T>();
        Array<T>(const Array &origin);
        Array<T> &operator=(const Array &origin);
        T& operator[](int index);
        const T& operator[](int index) const;
        int size() const;
};

template <typename T>
Array<T>::Array() : data(NULL), _size(0)
{
    std::cout << "Array default constructor called\n";
}

template <typename T>
Array<T>::Array(unsigned int value)
{
    std::cout << "Array constructor with an int called\n";
    _size = value;
    data = new T[_size]();
    std::cout << "An array of size : " << value << " was created\n";
}

template <typename T>
Array<T>::~Array()
{
    std::cout << "Array destructor called\n";
    delete[] data;
    std::cout << "Array of size : " << _size << " deleted\n";
}

template <typename T>
Array<T>::Array(const Array &origin)
{
    std::cout << "Array copy constructor called\n";
    if (this != &origin)
    {
        this->_size = origin._size;
        this->data = new T[_size]();
        for (unsigned int i = 0; i < this->_size; i++)
        {
            this->data[i] = origin.data[i];
        }
    }
    std::cout << "Array of size : " << _size << " copy constructed\n";
}

template <typename T>
Array<T>& Array<T>::operator=(const Array &origin)
{
    std::cout << "Array assignment operator\n";
    if (this != &origin)
    {
        delete[] this->data;
        this->_size = origin._size;
        this->data = new T[this->_size]();
        for (unsigned int i = 0; i < this->_size; i++)
        {
            this->data[i] = origin.data[i];
        }
    }
    return *this;
}

template <typename T>
T& Array<T>::operator[](int index)
{
    if (index < 0 || (unsigned int)index >= this->_size)
    {
        // exception to do 
        std::cout << "Array index out of bound, exiting";
        exit(0);
    }
    return this->data[index];
}

template <typename T>
const T& Array<T>::operator[](int index) const
{
    if (index < 0 || (unsigned int)index >= this->_size)
    {
        // exception to do 
        std::cout << "Array index out of bound, exiting";
        exit(0);
    }
    return this->data[index];
}

template <typename T>
int Array<T>::size() const
{
    return this->_size;
}

#endif