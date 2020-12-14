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

    int canvasWidth;
    int canvasHeight;

    // canvasWidth =  600;
    // canvasHeight = 600;

    sf::VideoMode desktopDetails = sf::VideoMode::getDesktopMode();
    canvasWidth = desktopDetails.width   - 200;
    canvasHeight = desktopDetails.height - 200;

    sf::RenderWindow window(sf::VideoMode(canvasWidth, canvasHeight), "Camera3D", sf::Style::Close);// | sf::Style::Fullscreen);
    window.setFramerateLimit(FPSCAP);

    sf::Vector3f boxdim = sf::Vector3f(100.0f,200.0f,400.0f);

    Box box(sf::Vector3f((float) canvasWidth/2.0f + boxdim.x/2.0f,(float) canvasHeight/2.0f + boxdim.y/2.0f,150.0f), boxdim);
    Camera camera(sf::Vector3f(100.0f,200.0f,100.0f), sf::Vector3f((float) canvasWidth,(float) canvasHeight,500), 500.0f);

    window.setMouseCursorVisible(false);

    sf::Clock clock = sf::Clock();
    float dt;

    window.setFramerateLimit(FPSCAP);



    // bool b = true;

    while(window.isOpen()) {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            window.close();
        }

        // if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
        //     box = Box(sf::Vector3f(1*250.0f,1*300.0f,1*300.0f), sf::Vector3f(100.0f,200.0f,400.0f));
        //     std::cout << "!" << std::endl;
        // }

        // if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        //     continue;
        // }

        // follows mouse
        // sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        // box.pos.x = (float) mousePos.x;
        // box.pos.y = (float) mousePos.y;

        dt = clock.restart().asSeconds();

        // follows mouse slowly
        // sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        // sf::Vector3f mPos = sf::Vector3f((float) mousePos.x, (float) mousePos.y, box.pos.z+box.dim.z/2.0f);

        // sf::Vector3f toMove = -((box.pos+box.dim/2.0f)-camera.origin);
        // toMove /= (toMove.x+toMove.y);
        // toMove *= dt * 5000;

        // if(toMove.x > 1 && toMove.y > 1 && toMove.z > 1) {
            // box.translate(toMove);
        // }

        box.rotateX(1.2f * dt);
        box.rotateY(0.4f * dt);
        box.rotateZ(0.3f * dt);

        // sf::Vector3f toMove = -((box.pos+box.dim/2.0f) - camera.origin);
        // toMove /= std::sqrt(toMove.x*toMove.x+toMove.y*toMove.y);
        // toMove *= 5.0f;

        // if(toMove.x > 1 || toMove.y > 1) {
        //     box.translate(toMove);
        // }


        // Matrix3 m1(8.0f,2.0f,3.0f,1.0f,2.0f,3.0f,0.0f,1.0f,2.0f);
        // Matrix3 m2(1.0f,1.0f,2.0f,3.0f,-5.0f,1.0f,2.0f, 3.0f, 4.0f);
        // Matrix3 m3 = m1*m2;
        // std::cout << m3.getString() << std::endl;
        // m1 = m1*m2;
        // std::cout << m1.getString() << std::endl << m2.getString() << std::endl << (m1*m2).getString() << std::endl << std::endl;

        // float test[9] = {8.0f,2.0f,3.0f,1.0f,2.0f,3.0f,0.0f,1.0f,2.0f};
        // Matrix3 mtest = Matrix3(test);
        // Matrix3 m = m1*m2;
        // std::cout << m.getString() << std::endl;

        // std::cout << "VALS: ";
        // for(int i = 0; i < 9; i++) {
        //     std::cout << mtest.vals[i] << " ";
        // }

        // std::cout << std::endl;

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

        camera.renderBox(&window, box);

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