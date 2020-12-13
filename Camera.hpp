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
        float focalLength;

        Camera(sf::Vector3f, float);

        void renderBox(sf::RenderWindow *, Box);
};