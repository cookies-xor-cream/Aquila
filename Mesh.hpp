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

        Mesh(std::string);
        Mesh(std::vector<Triangle>);

        void addTriangle(Triangle);
        void loadObjFile(std::string&, std::vector<Vector3>*, std::vector<std::array<int, 3>>*);

        void draw(sf::RenderWindow&);
};