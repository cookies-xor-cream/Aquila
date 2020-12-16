#ifndef AQUILAHPP
#define AQUILAHPP
    #include "Aquila.hpp"
#endif

#ifndef VECTOR4HPP
#define VECTOR4HPP
    #include "Vector4.hpp"
#endif

class Matrix4 {
    public:
        float vals[16];

        Matrix4();

        Matrix4(
            float, float, float, float,
            float, float, float, float,
            float, float, float, float,
            float, float, float, float
        );

        Matrix4(float[16]);

        Matrix4(Vector4, Vector4, Vector4, Vector4);

        Vector4 transform(Vector4&);

        std::string getString();
};