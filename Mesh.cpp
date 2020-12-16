#ifndef MESHHPP
#define MESHHPP
    #include "Mesh.hpp"
#endif

Mesh::Mesh() {

}

Mesh::Mesh(std::vector<Triangle> triangles) {
    this->triangles = triangles;
};

void Mesh::addTriangle(Triangle tri) {
    this->triangles.push_back(tri);
}

void Mesh::draw(sf::RenderWindow &window) {
    sf::ConvexShape triangle;
    triangle.setPointCount(3);
}