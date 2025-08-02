#pragma once

#include "../math/Matrix4.h"
#include "../scene/Transform.h"

class Camera {
public:
    static Camera Perspective(float fovYInDegrees, float aspect, float znear, float zfar);
    static Camera Orthographic(float left, float right, float bottom, float top, float znear, float zfar);

    Matrix4 getProjection() const;
    Matrix4 getView() const;
    Transform& getTransform();
    const Transform& getTransform() const;
private:
    Transform transform;
    Matrix4 projection;
    Matrix4 view;
    explicit Camera(const Matrix4& proj);
};
