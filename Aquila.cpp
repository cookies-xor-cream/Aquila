#ifndef AQUILAHPP
#define AQUILAHPP
    #include "Aquila.hpp"
#endif

#ifndef CAMERAHPP
#define CAMERAHPP
    #include "Camera.hpp"
#endif

#define FPSCAP 63

int main(int argc, char *argv[]) {
    std::srand((unsigned int) std::time(NULL));

    sf::Clock clock = sf::Clock();
    float dt;

    sf::VideoMode desktopDetails = sf::VideoMode::getDesktopMode();
    int canvasWidth  = desktopDetails.width;
    int canvasHeight = desktopDetails.height;

    sf::RenderWindow window(sf::VideoMode(canvasWidth, canvasHeight), "Camera3D", sf::Style::Close);// | sf::Style::Fullscreen);

    window.setFramerateLimit(FPSCAP);
    window.setMouseCursorVisible(false);

    window.setFramerateLimit(FPSCAP);

    Vector3 vertices[] = {
        {0.0f, 0.0f, 0.0f},
        {1.0f, 0.0f, 0.0f},
        {0.0f, 1.0f, 0.0f},
        {1.0f, 1.0f, 0.0f},
        {0.0f, 0.0f, 1.0f},
        {1.0f, 0.0f, 1.0f},
        {0.0f, 1.0f, 1.0f},
        {1.0f, 1.0f, 1.0f},
    };

    Triangle arroftris[] = {
        Triangle(vertices[0], vertices[2], vertices[3]),
        Triangle(vertices[0], vertices[3], vertices[1]),
        Triangle(vertices[1], vertices[3], vertices[7]),
        Triangle(vertices[1], vertices[7], vertices[5]),
        Triangle(vertices[5], vertices[7], vertices[6]),
        Triangle(vertices[5], vertices[6], vertices[4]),
        Triangle(vertices[4], vertices[6], vertices[2]),
        Triangle(vertices[4], vertices[2], vertices[0]),
        Triangle(vertices[2], vertices[6], vertices[7]),
        Triangle(vertices[2], vertices[7], vertices[3]),
        Triangle(vertices[4], vertices[0], vertices[1]),
        Triangle(vertices[4], vertices[1], vertices[5])
    };

    std::vector<Triangle> triangles;
    for(int i = 0; i < sizeof(arroftris)/sizeof(Triangle); i++) {
        triangles.push_back(arroftris[i]);
    }

    // Mesh cuboid(triangles);
    Mesh cuboid("./Models/Cat/CatThing.obj");
    // Mesh cuboid("./Models/BoxThing/BoxThing.obj");

    Camera camera(Vector3(0.0f, 0.0f, 0.0f), M_PI_2, 1000.0f, 0.1f, (float) canvasWidth, (float) canvasHeight);

    // sf::Vector2i centerOfScreen(canvasWidth/2, canvasHeight/2);
    sf::Vector2i prevMPos = sf::Mouse::getPosition(window);

    while(window.isOpen()) {
        dt = clock.restart().asSeconds();

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            window.close();
        }

        Vector3 translation(
            (float) sf::Keyboard::isKeyPressed(sf::Keyboard::A) - (float) sf::Keyboard::isKeyPressed(sf::Keyboard::D),
            (float) sf::Keyboard::isKeyPressed(sf::Keyboard::W) - (float) sf::Keyboard::isKeyPressed(sf::Keyboard::S),
            (float) sf::Keyboard::isKeyPressed(sf::Keyboard::Q) - (float) sf::Keyboard::isKeyPressed(sf::Keyboard::E)
        );
        
        translation = translation * dt * 40.0f;

        // Matrix3 rotMatrix = Matrix3::getRotationMatrix(Vector3(camera.eulerAngles.x, camera.eulerAngles.y, 0.0f));
        // translation = rotMatrix.transform(translation);

        camera.translate(translation);

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
            sf::Vector2i mouseMove = prevMPos - sf::Mouse::getPosition(window);
            camera.rotate(Vector2((float) mouseMove.y, (float) mouseMove.x) * -0.0003f);
        }

        prevMPos = sf::Mouse::getPosition(window);

        // sf::Mouse::setPosition(centerOfScreen, window);

        camera.renderMesh(window, cuboid);

        window.display();
        window.clear();
    }

    std::cout << camera.projectionMatrix.getString() << std::endl;

    // Mesh m();
    // std::string fname = "./Models/Cat/12221_Cat_v1_l3.obj";

    // std::vector<std::array<float, 3>> vv;
    // std::vector<std::array<int, 3>> ff;

    // cuboid.loadObjFile(fname, &vv, &ff);

    return 0;
}


/*
Personal comment

Ubuntu WSL:
cd /mnt/c/users/aryag/onedrive/documents/github/Aquila
*/