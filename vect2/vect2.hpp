#pragma once

#include <iostream>

class vect2
{
private:
    int _x;
    int _y;
public:
    vect2();
    vect2(int x, int y);
    vect2(const vect2& oth);
    vect2&  operator=(const vect2& oth);
    ~vect2();
    // ------------------------------------
    vect2   operator+(const vect2& oth) const;
    vect2   operator-(const vect2& oth) const;
    vect2   operator-() const;
    vect2   operator*(int scalar) const;
    vect2&  operator+=(const vect2& oth);
    vect2&  operator-=(const vect2& oth);
    vect2&   operator*=(int scalar);
    int   operator[](int index) const;
    int&  operator[](int index);
    // -----------------------------------
    vect2&    operator++(void);
    vect2&    operator--(void);
    vect2   operator++(int);
    vect2   operator--(int);
    // -----------------------------------
    bool    operator==(const vect2& oth) const;
    bool    operator!=(const vect2& oth) const;
};

vect2   operator*(int scalar, const vect2& v);
std::ostream&   operator<<(std::ostream& stream, const vect2& v);