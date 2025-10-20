#include "searchable_tree_bag.hpp"

searchable_tree_bag::searchable_tree_bag() : tree_bag() {}
searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag& oth) : tree_bag(oth) {}
searchable_tree_bag&    searchable_tree_bag::operator=(const searchable_tree_bag& oth) {
    if (this != &oth)
    {
        tree_bag::operator=(oth);
    }
    return *this;
}

bool    searchable_tree_bag::has(int x) const {
    node    *temp = tree;
    while (temp)
    {
        if (temp->value == x)
            return true;
        else if (x < temp->value)
            temp = temp->l;
        else
            temp = temp->r;
    }
    return false;
}

searchable_tree_bag::~searchable_tree_bag() {}
