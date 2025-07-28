#include "Transform.h"
#include "../math/Vector3.h"

Transform::Transform() : position{}, rotation{}, scale{ 1, 1, 1 } {}
Transform::Transform(const Vector3& position) : position{ position }, rotation{}, scale{ 1, 1, 1 } {}
Transform::Transform(const Vector3& position, const Vector3& rotation) : position{ position }, rotation{ rotation }, scale{ 1, 1, 1 } {}
Transform::Transform(const Vector3& position, const Vector3& rotation, const Vector3& scale)
    : position{ position }, rotation{ rotation }, scale{ scale } {
}

Matrix4 Transform::getModel() const {
    Matrix4 T = Matrix4::Translate(position);
    Matrix4 R = Matrix4::RotateEuler(rotation);
    Matrix4 S = Matrix4::Scale(scale);
    return T * R * S;
}

