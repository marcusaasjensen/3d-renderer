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
        canvas.setPixel(x0, y0, 255, 255, 255);
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

void Rasterizer::fillTriangle(const Vector3& v0, const Vector3& v1, const Vector3& v2, Canvas& canvas, std::vector<float>& zBuffer) {
    int minX { (int) std::min({v0.x, v1.x, v2.x}) };
    int minY { (int) std::min({v0.y, v1.y, v2.y}) };
    int maxX { (int) std::max({v0.x, v1.x, v2.x}) };
    int maxY { (int) std::max({v0.y, v1.y, v2.y}) };

    minX = std::max(minX, 0);
    maxX = std::min(maxX, canvas.getWidth() - 1);
    minY = std::max(minY, 0);
    maxY = std::min(maxY, canvas.getHeight() - 1);

    Color color = Color::random();
    for (int i = minX; i <= maxX; ++i) {
        for (int j = maxY; j >= minY; --j) {
            Vector3 p(i + 0.5f, j + 0.5f, 0);
            Vector3 bary = Math::barycentricCoordinates(p, v0, v1, v2);
            if (bary.x >= 0 && bary.y >= 0 && bary.z >= 0) {
                float interpolatedZ = bary.x * v0.z + bary.y * v1.z + bary.z * v2.z;
                int bufferIndex = i + j * canvas.getWidth();

                if (interpolatedZ < zBuffer[bufferIndex]) {
                    zBuffer[bufferIndex] = interpolatedZ;
                    canvas.setPixel(i, j, color.r, color.g, color.b);
                }
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

void Rasterizer::drawZBuffer(const std::vector<float>& zBuffer, Canvas& canvas) {
    float zMin = std::numeric_limits<float>::infinity();
    float zMax = -std::numeric_limits<float>::infinity();

    for (float z : zBuffer) {
        if (z == std::numeric_limits<float>::infinity()) continue;
        if (z < zMin) zMin = z;
        if (z > zMax) zMax = z;
    }

    int width = canvas.getWidth();
    int height = canvas.getHeight();

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int idx = x + y * width;
            float z = zBuffer[idx];

            if (z == std::numeric_limits<float>::infinity()) {
                canvas.setPixel(x, y, 0, 0, 0);
                continue;
            }

            float normalized = (z - zMin) / (zMax - zMin);

            unsigned char intensity = static_cast<char>((1.0f - normalized) * 255);

            canvas.setPixel(x, y, intensity, intensity, intensity);
        }
    }
}
