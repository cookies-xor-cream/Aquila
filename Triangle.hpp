#ifndef AQUILAHPP
#define AQUILAHPP
    #include "Aquila.hpp"
#endif

#ifndef VECTOR3HPP
#define VECTOR3HPP
    #include "Vector3.hpp"
#endif

class Triangle {
    public:
        Vector3 vertices[3] = {
            Vector3(0.0f,0.0f,0.0f),
            Vector3(0.0f,0.0f,0.0f),
            Vector3(0.0f,0.0f,0.0f)
        };

        Triangle();
        Triangle(const Vector3&, const Vector3&, const Vector3&);
        Triangle(Vector3[3]);

        void print();
};