#ifndef QUATERNIONHPP
#define QUATERNIONHPP
    #include "Quaternion.hpp"
#endif

Quaternion::Quaternion(float w, float i, float j, float k) {
    this->w = w;
    this->i = i;
    this->j = j;
    this->k = k;
}

Quaternion::Quaternion(float w, sf::Vector3f q) {
    Quaternion(w, q.x, q.y, q.z);
}

Quaternion::Quaternion(sf::Vector3f q) {
    Quaternion(0.0f, q.x, q.y, q.z);
}