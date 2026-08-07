#pragma once

#include "searchable_bag.hpp"

class set
{
    private :
        searchable_bag *_bag;
    public :
        set(searchable_bag *bag);
        ~set();
        set(const set& other);
        //set& operator=(const set& other);
        bool has(int value) const;
        const searchable_bag& get_bag() const;
        void insert (int value);
        void insert (int *array, int size);
        void print() const;
        void clear();
};