#include "Transform.h"
#include "../math/Vector3.h"
#include "../math/Math.h"

Transform::Transform() : position{ 0, 0, 0 }, rotation{ 0, 0, 0 }, scale{ 1, 1, 1 } {}
Transform::Transform(const Vector3& position) : position{ position }, rotation{ 0, 0, 0 }, scale{ 1, 1, 1 } {}
Transform::Transform(const Vector3& position, const Vector3& rotation) : position{ position }, rotation{ rotation }, scale{ 1, 1, 1 } {}
Transform::Transform(const Vector3& position, const Vector3& rotation, const Vector3& scale)
    : position{ position }, rotation{ rotation }, scale{ scale } {
}

void Transform::setPosition(float x, float y, float z) {
    position = Vector3(x, y,z);
}

void Transform::setRotation(float xAngle, float yAngle, float zAngle) {
    float x{ Math::toRadians(xAngle) };
    float y{ Math::toRadians(yAngle) };
    float z{ Math::toRadians(zAngle) };
    rotation = Vector3(x, y,z);
}

void Transform::setScale(float x, float y, float z) {
    scale = Vector3(x, y, z);
}

Matrix4 Transform::getModel() const {
    Matrix4 T = Matrix4::Translate(position);
    Matrix4 R = Matrix4::RotateEuler(rotation);
    Matrix4 S = Matrix4::Scale(scale);
    return T * R * S;
}

Vector3 Transform::getForward() const {
    Matrix4 rot = Matrix4::RotateEuler(rotation);
    Vector4 forward = rot * Vector4(0, 0, -1, 0);
    return Vector3(forward.x, forward.y, forward.z).normalized();
}

Vector3 Transform::getUp() const {
    Matrix4 rot = Matrix4::RotateEuler(rotation);
    Vector4 up = rot * Vector4(0, 1, 0, 0);
    return Vector3(up.x, up.y, up.z).normalized();
}

Vector3 Transform::getRight() const {
    Matrix4 rot = Matrix4::RotateEuler(rotation);
    Vector4 right = rot * Vector4(1, 0, 0, 0);
    return Vector3(right.x, right.y, right.z).normalized();
}


