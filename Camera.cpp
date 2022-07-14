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

    this->directionalLight = Vector3(0.0f, 1.0f, 1.0f);
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

convexShape Camera::projectTriangle(Triangle &triangle, sf::RenderWindow &window) {
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

    float angleFromLight = std::acos((normal*this->directionalLight)/(normal.mag() * this->directionalLight.mag()));
    float angleFromCamera = std::acos((normal*triangleVertices[0])/(normal.mag() * triangleVertices[0].mag()));
    // std::cout << angleFromCamera << std::endl;

    float proportionOfLightReflectedBySurface = (1 - angleFromLight/(2*M_PI));
    float proportionOfLightReflectedToCamera = (1 - angleFromCamera/(2*M_PI));

    uint8_t intensityOfLight = (uint8_t) 255 * proportionOfLightReflectedBySurface * proportionOfLightReflectedToCamera;

    // std::cout << proportionOfLightReflectedBySurface << std::endl;

    sf::Color triangleColor(intensityOfLight, intensityOfLight, intensityOfLight);

    // std::cout << triangleColor;

    // std::cout << triangleColor.r << " " << triangleColor.g << " " << triangleColor.b << std::endl;

    sf::ConvexShape projectedTriangle;
    projectedTriangle.setFillColor(triangleColor);
    projectedTriangle.setPointCount(3);

    // projectedVertices[0].print();

    projectedTriangle.setPoint(0, sf::Vector2f(projectedVertices[0].x, projectedVertices[0].y));
    projectedTriangle.setPoint(1, sf::Vector2f(projectedVertices[1].x, projectedVertices[1].y));
    projectedTriangle.setPoint(2, sf::Vector2f(projectedVertices[2].x, projectedVertices[2].y));

    struct convexShape shape;

    shape.tri       = projectedTriangle;
    shape.dotProd   = dotProduct;
    shape.depth     = triangleVertices[0].z;

    return shape;
}

void Camera::renderMesh(sf::RenderWindow &window, Mesh &mesh) {
    std::vector<convexShape> triangleBuffer;
    
    for(Triangle &triangle : mesh.triangles) {
        struct convexShape shape = this->projectTriangle(triangle, window);
        if(shape.dotProd < 0.0f) {
            triangleBuffer.push_back(shape);
        }
    }

    std::sort(triangleBuffer.begin(), triangleBuffer.end(),
        [](const struct convexShape &a, const struct convexShape &b) -> bool {
            return a.depth > b.depth;
        }
    );

    for(convexShape &triangle : triangleBuffer) {
        window.draw(triangle.tri);
    }

    // for(Triangle &triangle : mesh.triangles) {
    //     triangleBuffer.push_back(this->projectTriangle(triangle, window));
    //     // triangle.print();
    // }
}