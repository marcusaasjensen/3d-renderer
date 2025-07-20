#pragma once
#include "Vector3.h"

struct Vector4 {
    float x, y, z, w;

    Vector4();
    Vector4(float x, float y, float z, float w);
    Vector4(const Vector3& v, float w = 1.0f);

    Vector4 operator+(const Vector4& other) const;
    Vector4 operator*(float scalar) const;
    Vector3 toVector3();
};