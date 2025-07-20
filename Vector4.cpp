#include "Vector4.h"

Vector4::Vector4() : x{ 0 }, y{ 0 }, z{ 0 }, w{ 0 } {}
Vector4::Vector4(float x, float y, float z, float w) : x{ x }, y{ y }, z{ z }, w{ w } {}
Vector4::Vector4(const Vector3& v, float w = 1.0f) : x{ v.x }, y{ v.y }, z{ v.z }, w{ w } {}

Vector4 Vector4::operator*(float scalar) const {
    return Vector4(x * scalar, y * scalar, z * scalar, w * scalar);
}

Vector3 Vector4::toVector3() const {
    return Vector3(x, y, z);
}

Vector4 Vector4::operator+(const Vector4& v) const {
    return Vector4(x + v.x, y + v.y, z + v.z, w + v.w);
}