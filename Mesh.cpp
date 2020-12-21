#ifndef MESHHPP
#define MESHHPP
    #include "Mesh.hpp"
#endif

Mesh::Mesh(std::string filepath) {
    std::vector<Vector3> vertices;
    std::vector<std::array<int,   3>> faces;

    this->loadObjFile(filepath, &vertices, &faces);

    for(std::array<int, 3> &face : faces) {
        Vector3 verticesInTri[3] = {
            vertices[face[0]-1],
            vertices[face[1]-1],
            vertices[face[2]-1]
        };

        // Vector3 vertexVectors[3] = {
        //     Vector3(verticesInTri[0][0], verticesInTri[0][1], verticesInTri[0][2]),
        //     Vector3(verticesInTri[1][0], verticesInTri[1][1], verticesInTri[1][2]),
        //     Vector3(verticesInTri[2][0], verticesInTri[2][1], verticesInTri[2][2])
        // };

        Triangle triangle(verticesInTri);
        this->triangles.push_back(triangle); 
        // triangle.print();
    }

    std::cout << "rendered" << std::endl;
}

Mesh::Mesh(std::vector<Triangle> triangles) {
    this->triangles = triangles;
};

void Mesh::addTriangle(Triangle tri) {
    this->triangles.push_back(tri);
}

void Mesh::loadObjFile(std::string &filepath, std::vector<Vector3> *vertices, std::vector<std::array<int, 3>> *faces) {
    std::string line;
    std::ifstream inputFile(filepath);

    if(inputFile.is_open()) {
        while(std::getline(inputFile, line)) {
            std::stringstream lineStream;
            lineStream << line;

            std::string rowType;
            lineStream >> rowType;

            if(rowType == "v") {
                float data[3];
                // std::string junk;
                // lineStream >> data[0] >> junk >> data[1] >> junk >> data[2];

                lineStream >> data[0] >> data[1] >> data[2];
                vertices->push_back(Vector3(data));
            }

            else if(rowType == "f") {
                std::array<int, 3> data;
                // std::string junk;
                // lineStream >> junk >> data[0] >> junk >> data[1] >> junk >> data[2];

                lineStream >> data[0] >> data[1] >> data[2];
                faces->push_back(data);
            }
        }
    }

    else {
        std::cout << "File failed to open" << std::endl;
    }
    
    // for(float row[3] : vertices) {
    //     for(float &f : row) {
    //         std::cout << f;
    //     }

    //     std::cout << std::endl;
    // }
}

void Mesh::draw(sf::RenderWindow &window) {
    sf::ConvexShape triangle;
    triangle.setPointCount(3);
}