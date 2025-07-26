#include <iostream>
#include "Renderer.h"
#include "Shape.h"
#include "Scene.h"
#include "Vector3.h"
#include "Camera.h"

const int WIDTH{ 1920 };
const int HEIGHT{ 1080 };

static Scene createScene() {
    SceneObject cube = Shape::Cube();
    cube.getTransform().position = Vector3(-2.0f, 0.0f, -4.5f);
    cube.getTransform().rotation = Vector3(0.0f, 30.0f, 90.0f);

    SceneObject sphere = Shape::Sphere();
    sphere.getTransform().position = Vector3(1.0f, -0.25f, -2.5f);

    SceneObject tetra = Shape::Tetrahedron();
    tetra.getTransform().position = Vector3(1.0f, 1.0f, -4.0f);
    tetra.getTransform().rotation = Vector3(0.0f, 45.0f, 0.0f);

    SceneObject cylinder = Shape::Cylinder();
    cylinder.getTransform().position = Vector3(0.0f, 0.0f, -4.0f);
    cylinder.getTransform().rotation = Vector3(120.0f, 10.0f, 10.0f);

    Scene scene("MyScene");
    scene.addObject(cube);
    scene.addObject(sphere);
    scene.addObject(tetra);
    scene.addObject(cylinder);

    return scene;
}

static Camera createCamera() {
    float fovYInDegrees{ 45.0f };
    float aspect{ static_cast<float>(WIDTH) / HEIGHT };
    float znear{ 0.1f };
    float zfar{ 100.0f };
    Camera camera = Camera::Perspective(fovYInDegrees, aspect, znear, zfar);
    return camera;
}

static void render(Scene scene, Camera camera, const std::string& filename) {
    Renderer renderer(WIDTH, HEIGHT);
    renderer.getCanvas().clear();
    renderer.render(scene, camera);
    renderer.saveImage("output.ppm");
}

int main() {
    Scene scene = createScene();
    Camera camera = createCamera();
    render(scene, camera, "output.ppm");
}
