#pragma once
#include "searchable_bag.hpp"

class set
{
private:
    searchable_bag  &_bag;
    set();
public:
    set(searchable_bag& _bag);
    set(const set& oth);
    set&    operator=(const set& oth);
    ~set();
    void    insert(int x);
    void    insert(int *arr, int size);
    void    print() const;
    void    clear();
    bool    has(int x) const;
    searchable_bag&  get_bag() const;
};
