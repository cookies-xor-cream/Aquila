#ifndef BOXHPP
#define BOXHPP
    #include "Box.hpp"
#endif

Box::Box(sf::Vector3f pos, sf::Vector3f dimensions) {
    this->pos = pos;
    this->dim = dimensions;
    this->center = pos + dimensions/2.0f;
    this->eulerAngles = sf::Vector3f(0.0f,0.0f,0.0f);
    // for(int i = 0; i < 3; i++) {
    //     this->eulerAngles[i] = 0.0f;       // x,y,z euler angle
    // }
}

void Box::getVertexLocations(sf::Vector3f vertexLocations[8]) {
    sf::Vector3f vertices[8] = {
        this->pos,
        this->pos + sf::Vector3f(this->dim.x, 0, 0),
        this->pos + sf::Vector3f(this->dim.x, this->dim.y, 0),
        this->pos + sf::Vector3f(0, this->dim.y, 0),
        this->pos + sf::Vector3f(0, this->dim.y, this->dim.z),
        this->pos + this->dim,
        this->pos + sf::Vector3f(this->dim.x, 0, this->dim.z),
        this->pos + sf::Vector3f(0, 0, this->dim.z)
    };

    // Matrix3 rotMatrix = this->getRotationMatrix();
    Matrix3 rotMatrix = Matrix3::getRotationMatrix(this->eulerAngles);

    // std:: cout << rotMatrix.getString() << std::endl;

    for(int i = 0; i < 8; i++) {
        vertices[i] -= this->center;
        vertices[i] = rotMatrix.transform(vertices[i]);
        vertices[i] += this->center;
    }

    for(int i = 0; i < 8; i++) {
        vertexLocations[i] = vertices[i];
    }
}

void Box::translate(sf::Vector3f displacement) {
    this->pos += displacement;
}

void Box::rotateX(float angle) {
    this->eulerAngles.x += angle;
}

void Box::rotateY(float angle) {
    this->eulerAngles.y += angle;
}

void Box::rotateZ(float angle) {
    this->eulerAngles.z += angle;
}