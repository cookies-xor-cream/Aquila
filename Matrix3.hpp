#ifndef AQUILAHPP
#define AQUILAHPP
    #include "Aquila.hpp"
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

        Matrix3(sf::Vector3f, sf::Vector3f, sf::Vector3f);  // takes row vectors

        sf::Vector3f transform(sf::Vector3f);

        std::string getString();

    private:
        
        float tranposeVals[9];
};