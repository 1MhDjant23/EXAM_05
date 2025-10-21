#pragma once
#include <iostream>
#include <vector>

class bigint
{
private:
    std::vector<int>    _number;
    public:
    bigint();
    bigint(size_t number);
    bigint(const bigint& oth);
    bigint& operator=(const bigint& oth);
    ~bigint();
    // ---------------------
    size_t  toInt() const;
    void    addBitsLeft(int size);
    const std::vector<int>& getNumber() const;
    bigint  operator+(const bigint& oth) const;
    bigint& operator+=(const bigint& oth);
    bigint  operator++();
    bigint  operator++(int);
    bigint  operator<<(int shift) const;
    bigint& operator<<=(int shift);

};

// bigint& bigint::operator<<=()
void    bigint::addBitsLeft(int size) {
    for (int i = 0; i < size; i++)
    {
        _number.insert(_number.begin(), 0);
    }
}
bigint  bigint::operator<<(int shift) const {
    bigint  tmp(*this);
    tmp.addBitsLeft(shift);
    return tmp;
}


bigint bigint::operator++(int) {
    bigint  tmp(*this);
    this->operator+=(1);
    return tmp;
}

bigint  bigint::operator++() {
    bigint  tmp(this->toInt() + 1);
    *this = tmp;
    return tmp;
}
bigint  bigint::operator+(const bigint& oth) const {
    return (bigint(this->toInt() + oth.toInt()));
}

bigint& bigint::operator+=(const bigint& oth) {
    bigint  temp(this->toInt() + oth.toInt());
    *this = temp;;
    return *this;
}

size_t bigint::toInt() const {
    size_t n = 0;
    for (int i = _number.size() - 1; i >= 0; i--)
    {
        n = (n * 10) + _number.at(i);
    }
    return n;
}

const std::vector<int>& bigint::getNumber() const {
    return _number;
}

bigint::bigint() {}

bigint::bigint(size_t number) {
    while (number)
    {
        _number.push_back(number % 10);
        number /= 10;
    }
}

bigint& bigint::operator=(const bigint& oth) {
    if (this != &oth)
    {
        this->_number.operator=(oth._number);
    }
    return *this;
}
bigint::bigint(const bigint& oth) {
    _number = oth._number;
}

bigint::~bigint()
{
}

std::ostream&   operator<<(std::ostream& stream, const bigint& obj) {
    const   std::vector<int>&   tmp = obj.getNumber();
    if (tmp.empty())
    {
        stream << '0';
        return stream;
    }
    for (int i = tmp.size() - 1; i >= 0; i--)
    {
        stream << tmp[i];
    }
    return stream;
}

