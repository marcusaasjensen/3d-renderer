#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include "SceneObject.h"
#include "Shape.h"

const int WIDTH = 1920;
const int HEIGHT = 1080;

int main() {
    SceneObject cube = Shape::Cube();

    float fovY = 0.7854f;
    float aspect = static_cast<float>(WIDTH) / HEIGHT;
    float znear = 0.1f;
    float zfar = 100.0f;

    Matrix4 model = Matrix4::translateZ(-3.0f);
    Matrix4 proj = Matrix4::perspective(fovY, aspect, znear, zfar);

    // RGB buffer, initialized to black
    std::vector<unsigned char> framebuffer(WIDTH * HEIGHT * 3, 0);

    for (auto& vertex : cube.getMesh().vertices) {
        Vector4 v(vertex.position);
        Vector4 projected = proj * (model * v);

        if (projected.w != 0.0f) {
            projected.x /= projected.w;
            projected.y /= projected.w;
            projected.z /= projected.w;
        }

        int screenX = static_cast<int>((projected.x * 0.5f + 0.5f) * WIDTH);
        int screenY = static_cast<int>((1.0f - (projected.y * 0.5f + 0.5f)) * HEIGHT);

        if (screenX >= 0 && screenX < WIDTH && screenY >= 0 && screenY < HEIGHT) {
            int index = (screenY * WIDTH + screenX) * 3;
            framebuffer[index + 0] = 255; // Red
            framebuffer[index + 1] = 255; // Green
            framebuffer[index + 2] = 255; // Blue
        }
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
}
