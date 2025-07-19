#include "Transform.h"
#include "Vector3.h"

Transform::Transform() : position{}, rotation{}, scale{ 1, 1, 1 } {}
Transform::Transform(const Vector3& position) : position{ position }, rotation{}, scale{ 1, 1, 1 } {}
Transform::Transform(const Vector3& position, const Vector3& rotation) : position{ position }, rotation{ rotation }, scale{ 1, 1, 1 } {}
Transform::Transform(const Vector3& position, const Vector3& rotation, const Vector3& scale)
    : position{ position }, rotation{ rotation }, scale{ scale } {
}
