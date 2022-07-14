#ifndef AQUILAHPP
#define AQUILAHPP
    #include "Aquila.hpp"
#endif

#ifndef VECTOR3HPP
#define VECTOR3HPP
    #include "Vector3.hpp"
#endif

class Matrix3 {
    public:
    float vals[9];
        Matrix3 operator *(const Matrix3&);
        // void operator *=(const Matrix3&, const Matrix3&);

        Matrix3(
            float, float, float,
            float, float, float,
            float, float, float
        );

        Matrix3(float[9]);

        Matrix3(Vector3, Vector3, Vector3);  // takes row vectors

        static Matrix3 getRotationMatrix(Vector3);

        Vector3 transform(Vector3);

        std::string getString();

    private:
        
        float tranposeVals[9];
};