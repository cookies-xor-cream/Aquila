#ifndef VECTOR2HPP
#define VECTOR2HPP
    #include "Vector2.hpp"
#endif

Vector2::Vector2() {

}

Vector2::Vector2(float x, float y) {
    this->x = x;
    this->y = y;
}

Vector2 Vector2::operator +(const Vector2 &v) {
    return Vector2(this->x + v.x, this->y + v.y);
}

Vector2 Vector2::operator +=(const Vector2 &v) {
    this->x += v.x;
    this->y += v.y;

    return (*this);
}

Vector2 Vector2::operator *(float s) {
    return Vector2(this->x * s, this->y * s);
}

Vector2 operator *(float s, const Vector2 &v) {
    return Vector2(s*v.x, s*v.y);
}

Vector2 Vector2::mult(const Vector2 &v1, const Vector2 &v2) {
    return Vector2(v1.x * v2.x, v1.y * v2.y);
}

void Vector2::print() {
    std::cout << "[" << this->x << " " << this->y << "]" << std::endl;
}