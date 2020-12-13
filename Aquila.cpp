#ifndef AQUILAHPP
#define AQUILAHPP
    #include "Aquila.hpp"
#endif

#ifndef CAMERAHPP
#define CAMERAHPP
    #include "Camera.hpp"
#endif

#define FPSCAP 60

int main(int argc, char *argv[]) {
    std::srand((unsigned int) std::time(NULL));

    int canvasWidth;
    int canvasHeight;

    canvasWidth = 500;
    canvasHeight = 500;

    // sf::VideoMode desktopDetails = sf::VideoMode::getDesktopMode();
    // canvasWidth = desktopDetails.width;
    // canvasHeight = desktopDetails.height;

    sf::RenderWindow window(sf::VideoMode(canvasWidth, canvasHeight), "sfmltest", sf::Style::Close);// | sf::Style::Fullscreen);
    window.setFramerateLimit(FPSCAP);

    Box box(sf::Vector3f(3*200.0f,3*250.0f,3*300.0f), sf::Vector3f(100.0f,200.0f,400.0f));
    Camera camera(sf::Vector3f(100.0f,50.0f,100.0f), 400.0f);

    bool b = true;

    while(window.isOpen()) {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            window.close();
        }

        if(b) {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                b = false;
                continue;
            }
            continue;
        }
        camera.renderBox(&window, box);
        sf::Vector3f toMove = -(box.pos - camera.origin);
        toMove /= std::sqrt(toMove.x*toMove.x+toMove.y*toMove.y);
        toMove *= 5.0f;
        box.translate(toMove);

        // sf::Vector3f arr[8] = {
        //     sf::Vector3f(0.0f, 0.0f, 0.0f),
        //     sf::Vector3f(0.0f, 0.0f, 0.0f),
        //     sf::Vector3f(0.0f, 0.0f, 0.0f),
        //     sf::Vector3f(0.0f, 0.0f, 0.0f),
        //     sf::Vector3f(0.0f, 0.0f, 0.0f),
        //     sf::Vector3f(0.0f, 0.0f, 0.0f),
        //     sf::Vector3f(0.0f, 0.0f, 0.0f),
        //     sf::Vector3f(0.0f, 0.0f, 0.0f)
        // };

        // box.getVertexLocations(arr);

        // for(int i = 0; i < 8; i++) {
        //     std::cout << "[" << arr[i].x << ", " << arr[i].y << ", " << arr[i].z << "]" << std::endl;
        // }

        // std::cout << std::endl;

        window.display();
        window.clear();
    }

    return 0;
}


/*
Personal comment

Ubuntu WSL:
cd /mnt/c/users/aryag/onedrive/documents/github/Aquila
*/