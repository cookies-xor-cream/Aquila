#ifndef AQUILAHPP
#define AQUILAHPP
    #include "Aquila.hpp"
#endif

#ifndef MATRIX3
#define MATRIX3
    #include "Matrix3.hpp"
#endif




class Box {
    public:
        sf::Vector3f pos;
        sf::Vector3f dim;
        float eulerAngle[3];

        Box(sf::Vector3f, sf::Vector3f);

        void getVertexLocations(sf::Vector3f[8]);

        void translate(sf::Vector3f);
        void rotate();

        void rotateX(float);
        void rotateY(float);
        void rotateZ(float);

        Matrix3 getRotationMatrix();
};