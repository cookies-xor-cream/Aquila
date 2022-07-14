#ifndef MATRIX4
#define MATRIX4
    #include "Matrix4.hpp"
#endif

Matrix4::Matrix4() {

}

Matrix4::Matrix4(
    float a00, float a01, float a02 , float a03,
    float a10, float a11, float a12 , float a13,
    float a20, float a21, float a22 , float a23,
    float a30, float a31, float a32 , float a33
    ) {

    this->vals[0]  = a00;
    this->vals[1]  = a01;
    this->vals[2]  = a02;
    this->vals[3]  = a03;

    this->vals[4]  = a10;
    this->vals[5]  = a11;
    this->vals[6]  = a12;
    this->vals[7]  = a13;

    this->vals[8]  = a20;
    this->vals[9]  = a21;
    this->vals[10] = a22;
    this->vals[11] = a23;

    this->vals[12] = a30;
    this->vals[13] = a31;
    this->vals[14] = a32;
    this->vals[15] = a33;
}

Matrix4::Matrix4(float values[16]) {
    Matrix4(
        values[0],  values[1],  values[2],  values[3],
        values[4],  values[5],  values[6],  values[7],
        values[8],  values[9],  values[10], values[11],
        values[12], values[13], values[14], values[15]
    );
}

Matrix4::Matrix4(Vector4 v1, Vector4 v2, Vector4 v3, Vector4 v4) {
    Matrix4(
        v1.x, v1.y, v1.z, v1.k,
        v2.x, v2.y, v2.z, v2.k,
        v3.x, v3.y, v3.z, v3.k,
        v4.x, v4.y, v4.z, v4.k
    );
}

Vector4 Matrix4::transform(Vector4 &input) {
    auto A = this->vals;

    return Vector4(
        input.x * A[0]  + input.y * A[1]  + input.z * A[2]  + input.k * A[3],
        input.x * A[4]  + input.y * A[5]  + input.z * A[6]  + input.k * A[7],
        input.x * A[8]  + input.y * A[9]  + input.z * A[10] + input.k * A[11],
        input.x * A[12] + input.y * A[13] + input.z * A[14] + input.k * A[15]
    );
}

std::string Matrix4::getString() {
    std::ostringstream matrixStringStream;

    for(int i = 0; i < 4; i++) {
        matrixStringStream << "[";

        for(int j = 0; j < 4; j++) {
            int index = 4*i+j;

            float number = this->vals[index];
            char endChar = (j == 3) ? ']' : '\t';

            matrixStringStream << number << endChar;
        }

        matrixStringStream << std::endl;
    }

    return matrixStringStream.str();
}