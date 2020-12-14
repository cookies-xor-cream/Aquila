#ifndef CAMERAHPP
#define CAMERAHPP
    #include "Camera.hpp"
#endif


Camera::Camera(sf::Vector3f origin, sf::Vector3f viewBox, float focalLength) {
    this->origin = origin + viewBox/2.0f;
    this->viewBox = viewBox;
    this->focalLength = focalLength;
}

void Camera::renderBox(sf::RenderWindow *window, Box box) {
    sf::Vector3f boxVertices[8];
    box.getVertexLocations(boxVertices);

    sf::Vector2f projectedVertices[8];

    float xOffset = this->viewBox.x/2.0f;
    float yOffset = this->viewBox.y/2.0f;

    // std::cout << "og:" << this->origin.y << std::endl;

    for(int i = 0; i < 8; i++) {
        sf::Vector3f v = boxVertices[i];//projectedVertices[i];
        
        v = v - this->origin;
        
        float scaling = focalLength/(focalLength+v.z);
        // std::cout << v.z << " ";

        float x = scaling*v.x+xOffset;
        float y = scaling*v.y+yOffset;

        x = std::isnan(x) ? 0.0f : x;
        y = std::isnan(y) ? 0.0f : y;

        projectedVertices[i] = sf::Vector2f(x, y);

        // std::cout << x << " " << y << "\t" << projectedVertices[i].x << " " << projectedVertices[i].y << std::endl;
        // sf::CircleShape node(5.0f);
        // node.move(projectedVertices[i]);
        // window->draw(node);
    }

    // std::cout << std::endl;

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