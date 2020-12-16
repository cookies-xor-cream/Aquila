#ifndef AQUILAHPP
#define AQUILAHPP
    #include "Aquila.hpp"
#endif

class Vector2 {
    public:
        float x, y;

        Vector2();
        Vector2(float, float);

        Vector2 operator +(const Vector2&);
        Vector2 operator +=(const Vector2&);
        Vector2 operator *(float);

        static Vector2 mult(const Vector2&, const Vector2&);

        void print();
};