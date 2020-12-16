#ifndef AQUILAHPP
#define AQUILAHPP
    #include "Aquila.hpp"
#endif

#ifndef TRIANGLEHPP
#define TRIANGLEHPP
    #include "Triangle.hpp"
#endif

class Mesh {
    public:
        std::vector<Triangle> triangles;

        Mesh();
        Mesh(std::vector<Triangle>);

        void addTriangle(Triangle);

        void draw(sf::RenderWindow&);
};