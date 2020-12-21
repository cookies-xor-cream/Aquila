#ifndef TRIANGLEHPP
#define TRIANGLEHPP
    #include "Triangle.hpp"
#endif

Triangle::Triangle() {
    
}

Triangle::Triangle(const Vector3 &v1, const Vector3 &v2, const Vector3 &v3) {
    this->vertices[0] = v1;
    this->vertices[1] = v2;
    this->vertices[2] = v3;
}

Triangle::Triangle(Vector3 vertices[3]) {
    this->vertices[0] = vertices[0];
    this->vertices[1] = vertices[1];
    this->vertices[2] = vertices[2];
}

void Triangle::print() {
    std::cout << "Triangle:" << std::endl;
    for(int i = 0; i < 3; i++) {
        std::cout << "\t";
        this->vertices[i].print();
    }

    std::cout << std::endl;
}