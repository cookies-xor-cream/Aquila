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
    canvasWidth = desktopDetails.width   ;//- 200;
    canvasHeight = desktopDetails.height ;//- 200;

    sf::RenderWindow window(sf::VideoMode(canvasWidth, canvasHeight), "Camera3D", sf::Style::Close);// | sf::Style::Fullscreen);
    window.setFramerateLimit(FPSCAP);

    sf::Vector3f boxdim = sf::Vector3f(100.0f,200.0f,400.0f);

    Box box(sf::Vector3f((float) canvasWidth/2.0f + boxdim.x/2.0f,(float) canvasHeight/2.0f + boxdim.y/2.0f,150.0f), boxdim);
    // Box box2(sf::Vector3f((float) canvasWidth/2.0f + boxdim.x/2.0f+200.0f,(float) canvasHeight/2.0f + boxdim.y/2.0f+200.0f,150.0f), boxdim);
    // Camera camera(sf::Vector3f(100.0f,200.0f,100.0f), sf::Vector3f((float) canvasWidth,(float) canvasHeight,500), 300.0f);
    Camera camera(sf::Vector3f((float) -canvasHeight/2.0f,(float) -canvasHeight/2.0f,-150), sf::Vector3f((float) canvasWidth,(float) canvasHeight,500), 300.0f);

    Box box2(sf::Vector3f(400.0f, 300.0f, 1200.0f), boxdim);
    // Box box3(sf::Vector3f(900.0f, 450.0f, 400.0f), boxdim);
    // Box box4(sf::Vector3f(100.0f, 900.0f, 600.0f), boxdim);

    window.setMouseCursorVisible(false);

    sf::Clock clock = sf::Clock();
    float dt;

    window.setFramerateLimit(FPSCAP);

    sf::Vector2i prevMPos = sf::Mouse::getPosition(window);

    // sf::Vector2i middle();

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

        sf::Vector2i mPos = sf::Mouse::getPosition(window);
        sf::Vector2i mDiff = prevMPos - mPos;

        camera.rotateX((float) mDiff.y * 0.03f);
        camera.rotateZ((float) mDiff.x * 0.03f);

        // box.rotateY((float) mDiff.x * 0.03f);
        // box.rotateX((float) mDiff.y * 0.03f);

        // box2.rotateY((float) mDiff.x * 0.03f);
        // box2.rotateX((float) mDiff.y * 0.03f);

        // box3.rotateY((float) mDiff.x * 0.03f);
        // box3.rotateX((float) mDiff.y * 0.03f);

        // box4.rotateY((float) mDiff.x * 0.03f);
        // box4.rotateX((float) mDiff.y * 0.03f);

        prevMPos = mPos;

        dt = clock.restart().asSeconds();

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
            camera.rotateY(3.14f*dt);
        }


        if(sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
            camera.rotateY(-3.14f*dt);
        }



        if(sf::Keyboard::isKeyPressed(sf::Keyboard::J)) {
            box.translate(sf::Vector3f(-1.0f, 0.0f, 0.0f)*1000.0f*dt);
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {
            box.translate(sf::Vector3f(1.0f, 0.0f, 0.0f)*1000.0f*dt);
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::I)) {
            box.translate(sf::Vector3f(0.0f, -1.0f, 0.0f)*1000.0f*dt);
        }


        if(sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
            box.translate(sf::Vector3f(0.0f, 1.0f, 0.0f)*1000.0f*dt);
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::O)) {
            box.translate(sf::Vector3f(0.0f, 0.0f, -1.0f)*1000.0f*dt);
            box2.translate(sf::Vector3f(0.0f, 0.0f, -1.0f)*1000.0f*dt);
            // box3.translate(sf::Vector3f(0.0f, 0.0f, -1.0f)*1000.0f*dt);
            // box4.translate(sf::Vector3f(0.0f, 0.0f, -1.0f)*1000.0f*dt);
        }


        if(sf::Keyboard::isKeyPressed(sf::Keyboard::U)) {
            box.translate(sf::Vector3f(0.0f, 0.0f, 1.0f)*1000.0f*dt);
        }


        // follows mouse slowly
        // sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        // sf::Vector3f mPos = sf::Vector3f((float) mousePos.x, (float) mousePos.y, box.pos.z+box.dim.z/2.0f);

        // sf::Vector3f toMove = -((box.pos+box.dim/2.0f)-camera.origin);
        // toMove /= (toMove.x+toMove.y);
        // toMove *= dt * 5000;

        // if(toMove.x > 1 && toMove.y > 1 && toMove.z > 1) {
            // box.translate(toMove);
        // }

        // box.rotateX(1.2f * dt);
        // box.rotateY(0.4f * dt);
        // box.rotateZ(0.3f * dt);

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
        camera.renderBox(&window, box2);
        // camera.renderBox(&window, box3);
        // camera.renderBox(&window, box4);

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