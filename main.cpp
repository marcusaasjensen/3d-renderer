#include <iostream>
#include "Renderer.h"
#include "Shape.h"
#include "Matrix4.h"
#include "Vector3.h"

const int WIDTH = 1920;
const int HEIGHT = 1080;

int main() {
    SceneObject cube = Shape::Cube();
    SceneObject sphere = Shape::Sphere();

    float fovY = 0.7854f;
    float aspect = static_cast<float>(WIDTH) / HEIGHT;
    float znear = 0.1f;
    float zfar = 100.0f;

    Matrix4 cubeModel = Matrix4::translate(-1.0f, 0.0f, -3.0f) * Matrix4::rotate(30.0f, Vector3(0, 1, 0));
    Matrix4 sphereModel = Matrix4::translate(0.5f, 0.0f, -2.0f);

    Matrix4 proj = Matrix4::perspective(fovY, aspect, znear, zfar);

    Renderer renderer(WIDTH, HEIGHT);

    renderer.getCanvas().clear();

    renderer.render(sphere, sphereModel, proj);
    renderer.render(cube, cubeModel, proj);

    renderer.saveImage("output.ppm");

    std::cout << "Wrote output.ppm\n";
    return 0;
}

