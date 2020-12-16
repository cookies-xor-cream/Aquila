#ifndef MATRIX3
#define MATRIX3
    #include "Matrix3.hpp"
#endif

Matrix3::Matrix3(
    float a00, float a01, float a02,
    float a10, float a11, float a12,
    float a20, float a21, float a22
    ) {

        // std::cout << a00 << " " << a01 << " " << a02 << " " << a10 << " " << a11 << " " << a12 << " " << a20 << " " << a21 << " " << a22 << std::endl;

    this->vals[0] = a00;
    this->vals[1] = a01;
    this->vals[2] = a02;
    this->vals[3] = a10;
    this->vals[4] = a11;
    this->vals[5] = a12;
    this->vals[6] = a20;
    this->vals[7] = a21;
    this->vals[8] = a22;

    // for(int i = 0; i < 9; i++) {
    //     std::cout << this->vals[i] << " ";
    // }

    // std::cout << std::endl;
}

Matrix3::Matrix3(float values[9]) {
    Matrix3(
        values[0], values[1], values[2],
        values[3], values[4], values[5],
        values[6], values[7], values[8]
    );
}

Matrix3::Matrix3(Vector3 a, Vector3 b, Vector3 c) {
    Matrix3(
        a.x, a.y, a.z,
        b.x, b.y, b.z,
        c.x, c.y, c.z
    );
}

std::string Matrix3::getString() {
    std::ostringstream matrixStringStream;

    for(int i = 0; i < 3; i++) {
        matrixStringStream << "[";

        for(int j = 0; j < 3; j++) {
            int index = 3*i+j;

            float number = this->vals[index];
            char endChar = (j == 2) ? ']' : ' ';

            matrixStringStream << number << endChar;
        }

        matrixStringStream << std::endl;
    }

    return matrixStringStream.str();
}

Matrix3 Matrix3::operator *(const Matrix3& right) {
    // float A[9];
    // float B[9];

    auto A = this->vals;
    auto B = right.vals;

    // return Matrix3 (
    //     A[0]*B[0], A[0]*B[1], A[0]*B[2],
    //     A[1]*B[0], A[1]*B[1], A[1]*B[2],
    //     A[2]*B[0], A[2]*B[1], A[2]*B[2]
    // );

    float product[9];
    for(int i = 0; i < 9; i++) {
        product[i] = 0.0f;
    }

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {

            // ai marks the first index of the ith row
            // bi marks the first index of the jth column

            int ai = 3*i;
            int bi = j;

            // start the product at 0
            float p = 0.0f;

            // dot product of the row vector from A and column vector from B
            for(int k = 0; k < 3; k++) {
                p += A[ai]*B[bi];

                ai += 1;
                bi += 3;
            }

            // write the value into the product matrix
            product[3*i+j] = p;

            // std::cout << p << "(" << i << "," << j << ")" << "\t";

            // int ai = 3*i+j;
            // int bi = 3*j+i;

            // product[3*i+j] += A[ai]*B[bi];
            // p += A[ai]*B[bi];

            // std::cout << product[3*i+j] << "(" << A[ai] << "," << B[bi] << ")" << "\t";
        }

        // std:: cout << "p:" << p;

        // std::cout << std::endl;
    }

    // for(int i = 0; i < 3; i++) {
    //     std::cout << "[";
    //     for(int j = 0; j < 3; j++) {
    //         std::cout << product[3*i+j];

    //         if(j == 2) {
    //             std:: cout << "]";
    //         }

    //         else {
    //             std::cout << " ";
    //         }
    //     }

    //     std::cout << std::endl;
    // }

    // std::cout << std::endl;

    return Matrix3(
        product[0], product[1], product[2],
        product[3], product[4], product[5],
        product[6], product[7], product[8]
        );
}

// void Matrix3::operator *=(const Matrix3& right) {
//     this = (*this) * right;
// }

Vector3 Matrix3::transform(Vector3 input) {
    auto A = this->vals;
    return Vector3(
        input.x * A[0] + input.y * A[1] + input.z * A[2],
        input.x * A[3] + input.y * A[4] + input.z * A[5],
        input.x * A[6] + input.y * A[7] + input.z * A[8]
    );
}

Matrix3 Matrix3::getRotationMatrix(Vector3 eulerAngles) {
    float sine, cosine;

    sine = std::sin(eulerAngles.x);
    cosine = std::cos(eulerAngles.x);

    Matrix3 rotX(
        1.0f, 0.0f, 0.0f,
        0.0f, cosine, sine,
        0.0f, -sine, cosine
    );

    sine = std::sin(eulerAngles.y);
    cosine = std::cos(eulerAngles.y);

    Matrix3 rotY(
        cosine, 0.0f, sine,
        0.0f, 1.0f, 0.0f,
        -sine, 0.0f, cosine
    );

    sine = std::sin(eulerAngles.z);
    cosine = std::cos(eulerAngles.z);

    Matrix3 rotZ(
        cosine, -sine, 0.0f,
        sine, cosine, 0.0f,
        0.0f, 0.0f, 1.0f
    );

    Matrix3 rotationMatrix = (rotX * rotY * rotZ);
    return rotationMatrix;
}