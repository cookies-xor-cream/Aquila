#ifndef AQUILAHPP
#define AQUILAHPP
    #include "Aquila.hpp"
#endif

class Vector3 {
    public:
        float x, y, z;

        Vector3();
        Vector3(float, float, float);

        Vector3 operator +(const Vector3&);                         // Vector addition
        Vector3 operator +=(const Vector3&);

        Vector3 operator -(const Vector3&);                         // Vector subtraction
        Vector3 operator -=(const Vector3&);

        float   operator *(const Vector3&);                         // Dot product

        Vector3 operator *(const float);                            // Scalar product        
        Vector3 operator /(const float);                            // Scalar product

        static Vector3 mult(const Vector3&, const Vector3&);        // Element-wise multiplication of 2 vectors

        // bool operator ==(const Vector3&);                           // Vector equality
        // bool operator !=(const Vector3&);                           // Accounts for floating point arithmetic

        float mag();                                                // magnitude of the vector

        Vector3 normalize();                                        // Normalizes a vector to be of length 1

        static Vector3 cross(const Vector3&, const Vector3&);       // Cross product (non-commutative)
        static Vector3 unitCross(const Vector3&, const Vector3&);   // Returns a vector normal to both inputs

        // Vector3 normal(const Vector3&);                             // Returns an arbitrary normal vector
        // Vector3 unitNormal(const Vector3&);                         // Returns the unit (normalized) normal vector

        void print();
};