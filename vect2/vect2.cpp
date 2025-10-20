#include "vect2.hpp"

vect2::vect2() : _x(0), _y(0) {}

vect2::vect2(int x, int y) : _x(x), _y(y) {}
vect2::vect2(const vect2& oth) : _x(oth._x), _y(oth._y) {}

vect2&  vect2::operator=(const vect2& oth) {
    if (this != &oth)
    {
        _x = oth._x;
        _y = oth._y;
    }
    return *this;
}
vect2::~vect2(){}
// --------------------------------
vect2&   vect2::operator*=(int scalar) {
    this->_x = _x * scalar;
    this->_y = _y * scalar;
    return *this;
}
vect2   vect2::operator*(int scalar) const {
    return (vect2(_x * scalar, _y * scalar));
}
vect2   operator*(int scalar, const vect2& v) {
    return (vect2(v[0] * scalar, v[1] * scalar));
}
vect2   vect2::operator+(const vect2& oth) const {
    return (vect2(_x + oth._x, _y + oth._y));
}
vect2   vect2::operator-(const vect2& oth) const {
    return (vect2(_x - oth._x, _y - oth._y));
}
vect2   vect2::operator-() const{
    return (vect2(-_x, -_y));
}
vect2&  vect2::operator+=(const vect2& oth){
    _x += oth._x;
    _y += oth._y;
    return *this;
}
vect2&  vect2::operator-=(const vect2& oth){
    _x -= oth._x;
    _y -= oth._y;
    return *this;
}

int   vect2::operator[](int index) const {
    return ((index == 0) ? _x : _y);
}
int&    vect2::operator[](int index){
    return (index == 0 ? this->_x : this->_y);
}
// ------------------------------------------------
vect2&  vect2::operator++(void) {
    _x++;
    _y++;
    return *this;
}
vect2&  vect2::operator--(void) {
    _x--;
    _y--;
    return *this;
}
vect2  vect2::operator++(int) {
    vect2   temp = *this;
    _x++;
    _y++;
    return temp;
}
vect2  vect2::operator--(int) {
    vect2   temp = *this;
    _x--;
    _y--;
    return temp;
}
// --------------------------------------
bool    vect2::operator!=(const vect2& oth) const {
    if (_x != oth._x || _y != oth._y)
        return true;
    return false;    
}
bool    vect2::operator==(const vect2& oth) const {
    if (_x == oth._x || _y == oth._y)
        return true;
    return false;    
}
std::ostream&   operator<<(std::ostream& stream, const vect2& v) {
    stream << "{" << v[0] << ", " << v[1] << "}";
    return stream;
}

// v3 = 1.2
// v2 = 1,2 --> 1, 2 + 1, 2 ==> 2, 4
//------------------------------
//v1 = 0, 0 ==> -2, -4
// v2 = 2, 4 --> v3*2 = 2, 4 : v2 = v3 + {2, 4} ==> 3, 6 
// v2 = {3, 6}
// v2 = 3 * {3, 6} == v2={9, 18}
// ------------------------
//v2 += v2 += v3 -->  (v2 += v3 = {9, 18} + {1, 2} = {10, 20} )
// v2={10, 20}, --> (v2+=v2) ==> ({10, 20}+{10, 20} = 20, 40); 
//v2 = {20, 40}
//------------
// v1 *= 42 >> v1 = v1 * 42 ==> v1 = {-2, -4} * 42 ==> v1 = {-84, -168}
// ------------
// v1 = {0, 0} + {-84, -168} == v1 = {-84, -168}
//
// v1{-84, 12} --- v3{1, 2} false;
//

