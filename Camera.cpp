#ifndef CAMERAHPP
#define CAMERAHPP
    #include "Camera.hpp"
#endif


Camera::Camera(sf::Vector3f origin, float focalLength) {
    this->origin = origin;
    this->focalLength = focalLength;
}

void Camera::renderBox(sf::RenderWindow *window, Box box) {
    sf::Vector3f boxVertices[8];
    box.getVertexLocations(boxVertices);

    sf::Vector2f projectedVertices[8];

    // std::cout << "og:" << this->origin.y << std::endl;

    for(int i = 0; i < 8; i++) {
        boxVertices[i] = boxVertices[i] - this->origin;
        float scaling = focalLength/(focalLength+boxVertices[i].z);     // gotta add error handling for this shit
                                                                        // don't draw points with z = 0
        // std::cout << "scaling: " << scaling << std::endl;
        projectedVertices[i] = sf::Vector2f(scaling*boxVertices[i].x, scaling*boxVertices[i].y);

        // sf::CircleShape node(5.0f);
        // node.move(projectedVertices[i]);
        // window->draw(node);

        // sf::Vector2f v = projectedVertices[i];

        // std::cout << v.x << " " << v.y << std::endl;
    }

    sf::Vertex lines[12][2];
    for(int i = 0; i < 8; i++) {
        lines[i][0] = sf::Vertex(projectedVertices[i]);
        lines[i][1] = sf::Vertex(projectedVertices[(i+1)%8]);
    }

    lines[8][0] = sf::Vertex(projectedVertices[4]);
    lines[8][1] = sf::Vertex(projectedVertices[7]);

    lines[9][0] = sf::Vertex(projectedVertices[1]);
    lines[9][1] = sf::Vertex(projectedVertices[6]);

    lines[10][0] = sf::Vertex(projectedVertices[2]);
    lines[10][1] = sf::Vertex(projectedVertices[5]);

    lines[11][0] = sf::Vertex(projectedVertices[0]);
    lines[11][1] = sf::Vertex(projectedVertices[3]);

    for(int i = 0; i < 12; i++) {
        window->draw(lines[i], 2, sf::Lines);
    }

    // lines[8] = 

    // std::cout << std::endl;

    // window->draw(sf::RectangleShape(sf::Vector2f(50.0f,50.0f)));
}