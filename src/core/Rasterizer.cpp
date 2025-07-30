#include "Rasterizer.h"
#include "../math/Math.h"
#include "../utils/Color.h"
#include <algorithm>
#include <cmath>
#include <iostream>

void Rasterizer::drawLine(int x0, int y0, int x1, int y1, Canvas& canvas) {
    int dx { std::abs(x1 - x0) }, sx { x0 < x1 ? 1 : -1 };
    int dy { -std::abs(y1 - y0) }, sy { y0 < y1 ? 1 : -1 };
    int err{ dx + dy }, e2;

    while (true) {
        canvas.setPixel(x0, y0, 0, 0, 0);
        if (x0 == x1 && y0 == y1) break;
        e2 = 2 * err;
        if (e2 >= dy) { err += dy; x0 += sx; }
        if (e2 <= dx) { err += dx; y0 += sy; }
    }
}

void Rasterizer::drawTriangle(const Vector3& v0, const Vector3& v1, const Vector3& v2, Canvas& canvas) {
    drawLine((int)v0.x, (int)v0.y, (int)v1.x, (int)v1.y, canvas);
    drawLine((int)v1.x, (int)v1.y, (int)v2.x, (int)v2.y, canvas);
    drawLine((int)v2.x, (int)v2.y, (int)v0.x, (int)v0.y, canvas);
}


void Rasterizer::scanLine(int x0, int x1, int y, Canvas& canvas) {
    while (x0 != x1) {
        canvas.setPixel(x0, y, 255, 255, 255);
        x0 = x0 < x1 ? ++x0 : --x0;
    }
}

void Rasterizer::fillTriangle(const Vector3& v0, const Vector3& v1, const Vector3& v2, Canvas& canvas) {
    int minX { (int) std::min({v0.x, v1.x, v2.x}) };
    int minY { (int) std::min({v0.y, v1.y, v2.y}) };
    int maxX { (int) std::max({v0.x, v1.x, v2.x}) };
    int maxY { (int) std::max({v0.y, v1.y, v2.y}) };

    Color color = Color::random();

    for (int i { minX }; i <= maxX; ++i) {
        for (int j { maxY }; j >= minY; --j) {
            if (Rasterizer::pointInTriangle(Vector3(i, j, 0),  v0, v1, v2)) {
                canvas.setPixel(i, j, color.r, color.g, color.b);
            }
        }
    }
}

bool Rasterizer::pointInTriangle(const Vector3& pt, const Vector3& v1, const Vector3& v2, const Vector3& v3) {
    int d1 { Math::sign(pt, v1, v2) };
    int d2 { Math::sign(pt, v2, v3) };
    int d3 { Math::sign(pt, v3, v1) };

    bool has_neg { (d1 < 0) || (d2 < 0) || (d3 < 0) };
    bool has_pos{ (d1 > 0) || (d2 > 0) || (d3 > 0) };

    return !(has_neg && has_pos);
}