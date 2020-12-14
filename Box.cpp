#ifndef BOXHPP
#define BOXHPP
    #include "Box.hpp"
#endif

Box::Box(sf::Vector3f pos, sf::Vector3f dimensions) {
    this->pos = pos;
    this->dim = dimensions;
    for(int i = 0; i < 3; i++) {
        this->eulerAngle[i] = 0.0f;       // x,y,z euler angle
    }
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

    Matrix3 rotMatrix = this->getRotationMatrix();
    sf::Vector3f rotationOrigin = this->pos + this->dim/2.0f;

    // std:: cout << rotMatrix.getString() << std::endl;

    for(int i = 0; i < 8; i++) {
        vertices[i] -= rotationOrigin;
        vertices[i] = rotMatrix.transform(vertices[i]);
        vertices[i] += rotationOrigin;

        // sf::Vector3f v = vertices[i];
        // sf::Vector2f a = rotMatrix.transformPoint(v.x, v.y);
        // sf::Vector2f b = rotMatrix.transformPoint(v.z, 0);
        // vertices[i] = sf::Vector3f(a.x, a.y, b.x);
        // // vertices[i] = sf::Vector3f(
        // //     v.x * rMatrix.a00 + v.y * rMatrix.a01 + v.z * rMatrix.a02,
        // //     v.x * rMatrix.a10 + v.y * rMatrix.a11 + v.z * rMatrix.a12,
        // //     v.x * rMatrix.a20 + v.y * rMatrix.a21 + v.z * rMatrix.a22,
        // // );
        // vertices[i] += rotationOrigin;
    }

    for(int i = 0; i < 8; i++) {
        vertexLocations[i] = vertices[i];
    }
}

void Box::translate(sf::Vector3f displacement) {
    this->pos += displacement;
}

void Box::rotateX(float angle) {
    this->eulerAngle[0] += angle;
}

void Box::rotateY(float angle) {
    this->eulerAngle[1] += angle;
}

void Box::rotateZ(float angle) {
    this->eulerAngle[2] += angle;
}

Matrix3 Box::getRotationMatrix() {
    float sine, cosine;

    sine = std::sin(this->eulerAngle[0]);
    cosine = std::cos(this->eulerAngle[0]);

    Matrix3 rotX(
        1.0f, 0.0f, 0.0f,
        0.0f, cosine, sine,
        0.0f, -sine, cosine
    );

    sine = std::sin(this->eulerAngle[1]);
    cosine = std::cos(this->eulerAngle[1]);

    Matrix3 rotY(
        cosine, 0.0f, sine,
        0.0f, 1.0f, 0.0f,
        -sine, 0.0f, cosine
    );

    sine = std::sin(this->eulerAngle[2]);
    cosine = std::cos(this->eulerAngle[2]);

    Matrix3 rotZ(
        cosine, -sine, 0.0f,
        sine, cosine, 0.0f,
        0.0f, 0.0f, 1.0f
    );

    Matrix3 rotationMatrix = (rotX * rotY * rotZ);
    return rotationMatrix;
}