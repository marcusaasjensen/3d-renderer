#include "Vector3.h"
#include <cmath>

Vector3::Vector3() : x{ 0 }, y{ 0 }, z{ 0 } {}
Vector3::Vector3(float x, float y, float z) : x{ x }, y{ y }, z{ z } {}

Vector3 Vector3::operator+(const Vector3& other) const {
	return Vector3(x + other.x, y + other.y, z + other.z);
}

Vector3 Vector3::operator-(const Vector3& other) const {
    return Vector3(x - other.x, y - other.y, z - other.z);
}

Vector3 Vector3::operator*(const Vector3& other) const {
    return Vector3(x * other.x, y * other.y, z * other.z);
}

Vector3 Vector3::operator/(const Vector3& other) const {
    return Vector3(
        other.x != 0.0f ? x / other.x : 0.0f,
        other.y != 0.0f ? y / other.y : 0.0f,
        other.z != 0.0f ? z / other.z : 0.0f
    );
}

Vector3& Vector3::operator+=(const Vector3& other) {
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
}

Vector3& Vector3::operator-=(const Vector3& other) {
    x -= other.x;
    y -= other.y;
    z -= other.z;
    return *this;
}

Vector3& Vector3::operator*=(const Vector3& other) {
    x *= other.x;
    y *= other.y;
    z *= other.z;
    return *this;
}

Vector3& Vector3::operator/=(const Vector3& other) {
    x /= other.x != 0.0f ? other.x : 0.0f;
    y /= other.y != 0.0f ? other.y : 0.0f;
    z /= other.z != 0.0f ? other.z : 0.0f;
    return *this;
}

Vector3 Vector3::operator*(float scalar) const {
    return Vector3(x * scalar, y * scalar, z * scalar);
}

Vector3& Vector3::operator*=(float scalar) {
    x *= scalar;
    y *= scalar;
    z *= scalar;
    return *this;
}

bool Vector3::operator==(const Vector3& other) const {
    float const epsilon { 1e-6f };
    return std::abs(x - other.x) < epsilon &&
        std::abs(y - other.y) < epsilon &&
        std::abs(z - other.z) < epsilon;
}

Vector3 Vector3::normalized() const
{
    float length{ std::sqrt(x * x + y * y + z * z) };

    if (length == 0.0f) {
        return Vector3(0.0f, 0.0f, 0.0f);
    }

    return Vector3(x / length, y / length, z / length);
}

