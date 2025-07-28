#include <iostream>
#include "core/Renderer.h"
#include "geometry/Shape.h"
#include "scene/Scene.h"
#include "math/Vector3.h"
#include "core/Camera.h"

const int WIDTH{ 1920 };
const int HEIGHT{ 1080 };

static Scene createScene() {
    Object cube = Shape::Cube();
    cube.getTransform().position = Vector3(-2.0f, 0.0f, -4.5f);
    cube.getTransform().rotation = Vector3(0.0f, 30.0f, 90.0f);

    Object sphere = Shape::Sphere();
    sphere.getTransform().position = Vector3(1.0f, -0.25f, -2.5f);

    Object tetra = Shape::Tetrahedron();
    tetra.getTransform().position = Vector3(1.0f, 1.0f, -4.0f);
    tetra.getTransform().rotation = Vector3(0.0f, 45.0f, 0.0f);

    Object cylinder = Shape::Cylinder();
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

static void render(const Scene& scene, const Camera& camera, const std::string& filename) {
    Renderer renderer(WIDTH, HEIGHT);
    renderer.getCanvas().clear();
    renderer.render(scene, camera);
    renderer.saveImage(filename);
}

int main() {
    const Scene scene = createScene();
    const Camera camera = createCamera();
    const std::string filename = "output.ppm";

    render(scene, camera, filename);
    return 0;
}
