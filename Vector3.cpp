#include "Vector3.h"
#include <cmath>

Vector3::Vector3() : x(0), y(0), z(0) {}
Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

Vector3 Vector3::operator+(const Vector3& other) const {
	Vector3(x + other.x, y + other.y, z + other.z);
}

Vector3 Vector3::operator-(const Vector3& other) const {
    Vector3(x - other.x, y - other.y, z - other.z);
}

Vector3 Vector3::operator*(const Vector3& other) const {
    Vector3(x * other.x, y * other.y, z * other.z);
}

Vector3 Vector3::operator/(const Vector3& other) const {
    return Vector3(
        other.x != 0.0f ? x / other.x : 0.0f,
        other.y != 0.0f ? y / other.y : 0.0f,
        other.z != 0.0f ? z / other.z : 0.0f
    );
}


bool Vector3::operator==(const Vector3& other) const {
    float const epsilon { 1e-6f };
    return std::abs(x - other.x) < epsilon &&
        std::abs(y - other.y) < epsilon &&
        std::abs(z - other.z) < epsilon;
}