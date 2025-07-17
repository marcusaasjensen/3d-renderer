#pragma once

#include "Vector3.h"
#include "Color.h"

struct Vertex {
    Vector3 position;
    Vector3 normal;
    Color color;

    Vertex();
    Vertex(const Vector3& position);
    Vertex(const Vector3& position, const Color& color);
    Vertex(const Vector3& position, const Vector3& normal);
    Vertex(const Vector3& position, const Vector3& normal, const Color& color);
    Vertex(float x, float y, float z);
    Vertex(float x, float y, float z, float nx, float ny, float nz, const Color& color);
};
