#pragma once

#include <vector>
#include "Canvas.h"
#include "../math/Vector3.h"

class Rasterizer {
public:
    static void drawLine(int x0, int y0, int x1, int y1, Canvas& canvas);
    static void drawTriangle(const Vector3& v0, const Vector3& v1, const Vector3& v2, Canvas& canvas);
    static void fillTriangle(const Vector3& v0, const Vector3& v1, const Vector3& v2, Canvas& canvas, std::vector<float>& zBuffer);
    static bool pointInTriangle(const Vector3& pt, const Vector3& v1, const Vector3& v2, const Vector3& v3);
    static void drawZBuffer(const std::vector<float>& zBuffer, Canvas& canvas);
};