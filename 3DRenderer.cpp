#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include "SceneObject.h"
#include "Shape.h"

const int WIDTH = 1920;
const int HEIGHT = 1080;

static void drawLine(int x0, int y0, int x1, int y1, std::vector<unsigned char>& framebuffer) {
    int dx = std::abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
    int dy = -std::abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
    int err = dx + dy, e2;

    while (true) {
        if (x0 >= 0 && x0 < WIDTH && y0 >= 0 && y0 < HEIGHT) {
            int index = (y0 * WIDTH + x0) * 3;
            framebuffer[index + 0] = 255;
            framebuffer[index + 1] = 255;
            framebuffer[index + 2] = 255;
        }
        if (x0 == x1 && y0 == y1) break;
        e2 = 2 * err;
        if (e2 >= dy) { err += dy; x0 += sx; }
        if (e2 <= dx) { err += dx; y0 += sy; }
    }
}

int main() {
    SceneObject cube = Shape::Cube();

    float fovY = 0.7854f;
    float aspect = static_cast<float>(WIDTH) / HEIGHT;
    float znear = 0.1f;
    float zfar = 100.0f;

    Matrix4 model = Matrix4::translateZ(-10.0f) * Matrix4::rotate(30.0f, Vector3(0,1,1));
    Matrix4 proj = Matrix4::perspective(fovY, aspect, znear, zfar);

    std::vector<unsigned char> framebuffer(WIDTH * HEIGHT * 3, 0);

    const auto& mesh = cube.getMesh();
    for (size_t i = 0; i < mesh.indices.size(); i += 3) {
        Vector4 screenVerts[3];

        for (int j = 0; j < 3; ++j) {
            int idx = mesh.indices[i + j];
            Vector4 v(mesh.vertices[idx].position);
            v = proj * (model * v);

            if (v.w != 0.0f) {
                v.x /= v.w;
                v.y /= v.w;
                v.z /= v.w;
            }

            int screenX = static_cast<int>((v.x * 0.5f + 0.5f) * WIDTH);
            int screenY = static_cast<int>((1.0f - (v.y * 0.5f + 0.5f)) * HEIGHT);
            screenVerts[j] = Vector4((float)screenX, (float)screenY, 0.0f, 1.0f);
        }

        drawLine((int)screenVerts[0].x, (int)screenVerts[0].y, (int)screenVerts[1].x, (int)screenVerts[1].y, framebuffer);
        drawLine((int)screenVerts[1].x, (int)screenVerts[1].y, (int)screenVerts[2].x, (int)screenVerts[2].y, framebuffer);
        drawLine((int)screenVerts[2].x, (int)screenVerts[2].y, (int)screenVerts[0].x, (int)screenVerts[0].y, framebuffer);
    }

    std::ofstream out("output.ppm");
    out << "P3\n" << WIDTH << " " << HEIGHT << "\n255\n";
    for (int i = 0; i < WIDTH * HEIGHT * 3; i += 3) {
        out << (int)framebuffer[i] << " "
            << (int)framebuffer[i + 1] << " "
            << (int)framebuffer[i + 2] << "\n";
    }
    out.close();

    std::cout << "Wrote output.ppm\n";
    return 0;
}
