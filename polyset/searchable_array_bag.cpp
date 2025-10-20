#include "searchable_array_bag.hpp"

searchable_array_bag::searchable_array_bag() : array_bag() {}
searchable_array_bag::searchable_array_bag(const searchable_array_bag& oth) : array_bag(oth){}
searchable_array_bag&    searchable_array_bag::operator=(const searchable_array_bag& oth) {
    if (this != &oth)
    {
        array_bag::operator=(oth);
    }
    return *this;
}

bool    searchable_array_bag::has(int x) const {
    for (int i = 0; i < size; i++)
    {
        if (data[i] == x)
            return true;
    }
    return false;
}
searchable_array_bag::~searchable_array_bag()
{
}