#ifndef AQUILAHPP
#define AQUILAHPP
    #include "Aquila.hpp"
#endif

#ifndef MESHHPP
#define MESHHPP
    #include "Mesh.hpp"
#endif

#ifndef MATRIX4
#define MATRIX4
    #include "Matrix4.hpp"
#endif

#ifndef MATRIX3
#define MATRIX3
    #include "Matrix3.hpp"
#endif

#ifndef VECTOR2HPP
#define VECTOR2HPP
    #include "Vector2.hpp"
#endif

class Camera {
    public:
        Vector3 origin;
        Vector2 eulerAngles;
        float viewAngle, focalLength, minLength, maxLength, aspectRatio, w, h;

        Matrix4 projectionMatrix;

        Camera(Vector3, float, float, float, float, float);

        Matrix4 computeProjectionMatrix();

        void translate(Vector3);
        void rotate(Vector2);

        Vector2 projectVertexToScreen(Vector3&);
        sf::ConvexShape projectTriangle(Triangle&, sf::RenderWindow&);
        void renderMesh(sf::RenderWindow&, Mesh&); 
};