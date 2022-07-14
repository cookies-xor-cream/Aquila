#ifndef AQUILAHPP
#define AQUILAHPP
    #include "Aquila.hpp"
#endif

#ifndef VECTORHPP
#define VECTORHPP
    #include "Vector.hpp"
#endif

class Quaternion {
    public:
        Quaternion(float, float, float, float);
        Quaternion(float, Vector3 q);
        Quaternion(Vector3 q);

        Quaternion operator +(const Quaternion&, const Quaternion&);
        Quaternion operator *(const Quaternion&, const Quaternion&);

    private:
        float w, i, k, j;
};