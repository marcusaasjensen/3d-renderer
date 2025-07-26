// Camera.h
#pragma once
#include "Matrix4.h"

class Camera {
public:
    static Camera Perspective(float fovYInDegrees, float aspect, float znear, float zfar);
    static Camera Orthographic(float left, float right, float bottom, float top, float znear, float zfar);

    const Matrix4& getProjection() const;

private:
    Matrix4 projection;
    explicit Camera(const Matrix4& proj);
};
