#ifndef VECTOR4HPP
#define VECTOR4HPP
    #include "Vector4.hpp"
#endif

Vector4::Vector4() {
    
}

Vector4::Vector4(float x, float y, float z, float k) {
    this->x = x;
    this->y = y;
    this->z = z;
    this->k = k;
}

Vector4::Vector4(Vector3 v, float k) {
    this->x = v.x;
    this->y = v.y;
    this->z = v.z;
    this->k = k;
}