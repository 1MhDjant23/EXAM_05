#include "set.hpp"

set::set(searchable_bag& _bag) : _bag(_bag) {}

set&    set::operator=(const set& oth) {
    if (this != &oth)
    {
        _bag = oth._bag;
    }
    return *this;
}
set::set(const set& oth) : _bag(oth._bag) {}

set::~set() {
    this->_bag.clear();
}

void    set::insert(int x) {
    if (!_bag.has(x))
        this->_bag.insert(x);
}
void    set::insert(int *arr, int size) {
    for (int i = 0; i < size; i++)
    {
        if (!this->_bag.has(arr[i]))
            this->_bag.insert(arr[i]);
    }   
}
void    set::print() const {
    this->_bag.print();
}
void    set::clear() {
    this->_bag.clear();
}
bool    set::has(int x) const {
    return this->_bag.has(x);
}
searchable_bag& set::get_bag() const {
    return this->_bag;
}