#ifndef VECTOR3HPP
#define VECTOR3HPP
    #include "Vector3.hpp"
#endif

Vector3::Vector3() {
    
}

Vector3::Vector3(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector3::Vector3(float v[3]) {
    this->x = v[0];
    this->y = v[1];
    this->z = v[2];
}

Vector3 Vector3::operator +(const Vector3 &b) {
    Vector3 a = (*this);
    return Vector3(a.x+b.x, a.y+b.y, a.z+b.z);
}

Vector3 Vector3::operator +=(const Vector3 &b) {
    this->x += b.x;
    this->y += b.y;
    this->z += b.z;

    return *this;
}

Vector3 Vector3::operator -(const Vector3 &b) {
    Vector3 a = (*this);
    return Vector3(a.x-b.x, a.y-b.y, a.z-b.z);
}

Vector3 Vector3::operator -=(const Vector3 &b) {
    this->x -= b.x;
    this->y -= b.y;
    this->z -= b.z;
    
    return *this;
}

float Vector3::operator *(const Vector3 &b) {
    Vector3 a = (*this);
    return (a.x*b.x + a.y*b.y + a.z*b.z);
}

Vector3 Vector3::operator *(const float s) {
    return Vector3(s*this->x, s*this->y, s*this->z);
}

Vector3 operator *(const float s, const Vector3 &v) {
    return Vector3(s*v.x, s*v.y, s*v.z);
}

Vector3 Vector3::mult(const Vector3 &v1, const Vector3 &v2) {
    return Vector3(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z);
}

Vector3 Vector3::operator /(const float s) {
    return (*this)*(1/s);
}

bool operator ==(const Vector3 &a, const Vector3 &b) {
    float epsilon = 0.001;
    return (
        std::abs(a.x - b.x) < epsilon &&
        std::abs(a.x - b.x) < epsilon &&
        std::abs(a.x - b.x) < epsilon
    );
}

bool operator !=(const Vector3 &a, const Vector3 &b) {
    return a != b;
}

float Vector3::mag() {
    Vector3 v = (*this);
    return std::sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
}

Vector3 Vector3::normalize() {
    float magnitude = this->mag();
    return (*this)/magnitude;
}

Vector3 Vector3::cross(const Vector3 &a, const Vector3 &b) {
    return Vector3(
        a.y*b.z - b.y*a.z,
        a.z*b.x - b.z*a.x,
        a.x*b.y - b.x*a.y
    );
}

Vector3 Vector3::unitCross(const Vector3 &a, const Vector3 &b) {
    return Vector3::cross(a, b).normalize();
}

void Vector3::print() {
    std::cout << "[" << this->x << " " << this->y << " " << this->z << "]" << std::endl;
}