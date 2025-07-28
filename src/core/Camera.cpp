#include "Camera.h"
#include "../math/Math.h"

Camera::Camera(const Matrix4& proj) : projection(proj) {}

Camera Camera::Perspective(float fovYInDegrees, float aspect, float znear, float zfar) {
    return Camera(Matrix4::Perspective(Math::toRadians(fovYInDegrees), aspect, znear, zfar));
}

Camera Camera::Orthographic(float left, float right, float bottom, float top, float znear, float zfar) {
    return Camera(Matrix4::Orthographic(left, right, bottom, top, znear, zfar));
}

const Matrix4& Camera::getProjection() const {
    return projection;
}
