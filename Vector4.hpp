#ifndef AQUILAHPP
#define AQUILAHPP
    #include "Aquila.hpp"
#endif

#ifndef VECTOR3HPP
#define VECTOR3HPP
    #include "Vector3.hpp"
#endif

class Vector4 {
    public:
        float x, y, z, k;

        Vector4();
        Vector4(float, float, float, float);
        Vector4(Vector3, float);
};