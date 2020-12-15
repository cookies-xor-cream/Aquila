#ifndef AQUILAHPP
#define AQUILAHPP
    #include "Aquila.hpp"
#endif

#ifndef BOXHPP
#define BOXHPP
    #include "Box.hpp"
#endif

class Camera {
    public:
        sf::Vector3f origin;
        sf::Vector3f viewBox;
        sf::Vector3f eulerAngles;

        float focalLength;

        Camera(sf::Vector3f, sf::Vector3f, float);

        void renderBox(sf::RenderWindow *, Box);

        void rotateX(float);
        void rotateY(float);
        void rotateZ(float);
};