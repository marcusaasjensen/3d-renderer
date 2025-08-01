#pragma once
#include "Vector3.h"

struct Vector4 {
    float x, y, z, w;

    Vector4();
    Vector4(float x, float y, float z, float w);
    Vector4(const Vector3& v);

    Vector4 operator+(const Vector4& other) const;
    Vector4 operator*(float scalar) const;
    Vector3 toVector3() const;
};

inline std::ostream& operator<<(std::ostream& os, const Vector4& vec) {
    return os << "(" << vec.x << ", " << vec.y << ", " << vec.z << ", " << vec.w << ")";
}