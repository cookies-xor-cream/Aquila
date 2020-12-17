#ifndef AQUILAHPP
#define AQUILAHPP
    #include "Aquila.hpp"
#endif

#ifndef CAMERAHPP
#define CAMERAHPP
    #include "Camera.hpp"
#endif

Camera::Camera(Vector3 origin, float viewAngle, float maxLength, float minLength, float width, float height) { 
    std::cout << "construct " << width << " " << height << std::endl;   
    this->origin = origin;

    this->viewAngle = viewAngle;

    this->focalLength = maxLength/(maxLength-minLength);

    this->minLength = minLength;
    this->maxLength = maxLength;

    this->aspectRatio = height/width;
    this->projectionMatrix = this->computeProjectionMatrix();

    this->eulerAngles = Vector2(0.0f, 0.0f);

    this->w = width;
    this->h = height;
}

Matrix4 Camera::computeProjectionMatrix() {
    float tangent = std::tan(this->viewAngle/2.0f);
    float invTangent = std::isnan(tangent) ? 0.0f : tangent; //f


    return Matrix4(
        this->aspectRatio * invTangent,     0.0f,                               0.0f,                                   0.0f,
        0.0f,                               invTangent,                         0.0f,                                   0.0f,
        0.0f,                               0.0f,                               this->focalLength,                      1.0f,
        0.0f,                               0.0f,                               -this->focalLength * this->minLength,   0.0f
    );
}

void Camera::translate(Vector3 displacement) {
    this->origin += displacement;
    
    // this->origin.print();
}

void Camera::rotate(Vector2 rotation) {
    this->eulerAngles += rotation;
}

Vector4 Camera::transformToCameraView(Vector3 &vertex) {
    Vector3 vRot = vertex - this->origin;

    // vRot += Vector3(-0.4f, 0.0f, 0.0f);

    Matrix3 rotMatrix = Matrix3::getRotationMatrix(Vector3(this->eulerAngles.x, this->eulerAngles.y, 0.0f));

    vRot = rotMatrix.transform(vRot);

    Vector4 v(vRot, 1.0f);

    // if(v.k) {
    //     v.x /= v.k;
    //     v.y /= v.k;
    //     v.z /= v.k;
    // }

    return v;
}

Vector2 Camera::projectVertexToScreen(Vector3 &vertex) {
    // Vector3 vRot = vertex - this->origin;

    // vRot += Vector3(-0.4f, 0.0f, 10.0f);

    // Matrix3 rotMatrix = Matrix3::getRotationMatrix(Vector3(this->eulerAngles.x, this->eulerAngles.y, 0.0f));

    // vRot = rotMatrix.transform(vRot);

    // Vector4 v(vRot, 1.0f);

    Vector4 v = Vector4(vertex, 1.0f);

    v = this->projectionMatrix.transform(v);

    if(v.k) {
        v.x /= v.k;
        v.y /= v.k;
        v.z /= v.k;
    }

    Vector2 pV(v.x, v.y);
    pV = pV + Vector2(1.0f, 1.0f);
    pV = Vector2::mult(pV, Vector2(this->w, this->h) * 0.5f);

    return pV;
}

sf::ConvexShape Camera::projectTriangle(Triangle &triangle, sf::RenderWindow &window) {
    Vector4 transformedVertices[3] {
        this->transformToCameraView(triangle.vertices[0]),
        this->transformToCameraView(triangle.vertices[1]),
        this->transformToCameraView(triangle.vertices[2])
    };

    Vector3 triangleVertices[3];
    for(int i = 0; i < 3; i++) {
        Vector3 vertexLocation(
            transformedVertices[i].x,
            transformedVertices[i].y,
            transformedVertices[i].z
        );

        triangleVertices[i] = vertexLocation;
    }

    Vector3 edges[2] = {
        triangleVertices[1] - triangleVertices[0],
        triangleVertices[2] - triangleVertices[1]
    };                      // Only 2 edges are needed for a dot product as the final edge is coplanar

    Vector3 normal = Vector3::cross(edges[0], edges[1]);
    // Vector3 triangleCenterToOrigin = (triangleVertices[0] + triangleVertices[1] + triangleVertices[2])/3.0f - this->origin;

    float dotProduct = normal * triangleVertices[0];

    Vector2 projectedVertices[3];

    for(int i = 0; i < 3; i++) {
        projectedVertices[i] = this->projectVertexToScreen(triangleVertices[i]);
    }

    sf::ConvexShape projectedTriangle;
    projectedTriangle.setPointCount(3);

    // projectedVertices[0].print();

    projectedTriangle.setPoint(0, sf::Vector2f(projectedVertices[0].x, projectedVertices[0].y));
    projectedTriangle.setPoint(1, sf::Vector2f(projectedVertices[1].x, projectedVertices[1].y));
    projectedTriangle.setPoint(2, sf::Vector2f(projectedVertices[2].x, projectedVertices[2].y));

    for(int i = 0; i < 3; i++) {
        sf::Vertex edge[2] = {
            sf::Vertex(sf::Vector2f(projectedVertices[i].x, projectedVertices[i].y), sf::Color::Red),
            sf::Vertex(sf::Vector2f(projectedVertices[(i+1)%3].x, projectedVertices[(i+1)%3].y), sf::Color::Red)
        };

        if(dotProduct < 0.0f) {
            window.draw(edge, 2, sf::Lines);
        }
    }

    return projectedTriangle;
}

void Camera::renderMesh(sf::RenderWindow &window, Mesh &mesh) {
    std::vector<sf::ConvexShape> triangleBuffer;
    
    for(Triangle &triangle : mesh.triangles) {
        triangleBuffer.push_back(this->projectTriangle(triangle, window));
        // triangle.print();
    }

    // for(sf::ConvexShape &triangle : triangleBuffer) {
    //     window.draw(triangle);
    // }

    // for(Triangle &triangle : mesh.triangles) {
    //     triangleBuffer.push_back(this->projectTriangle(triangle, window));
    //     // triangle.print();
    // }
}