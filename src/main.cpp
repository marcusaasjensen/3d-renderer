#include <iostream>
#include "core/Renderer.h"
#include "geometry/Shape.h"
#include "scene/Scene.h"
#include "math/Vector3.h"
#include "core/Camera.h"
#include "math/Math.h"
#include "geometry/MeshImporter.h"

const int WIDTH{ 1920 };
const int HEIGHT{ 1080 };

static Scene createScene() {
    Object cube { Shape::Cube() };
    cube.getTransform().setPosition(-1.75f, -.5f, -3.9f);
    cube.getTransform().setRotation(30.0f, 40.0f, 60.0f);
    cube.getTransform().setScale(0.75f, 0.75f, 0.75f);

    Object sphere{ Shape::Sphere() };
    sphere.getTransform().setPosition(2.0f, -0.2f, -3.75f);
    sphere.getTransform().setRotation(30.0f, 30.0f, 0.0f);
    sphere.getTransform().setScale(1.0f, 1.0f, 1.0f);

    Object tetra { Shape::Tetrahedron() };
    tetra.getTransform().setPosition(1.f, .75f, -3.25f);
    tetra.getTransform().setRotation(30.0f, 90.0f, 45.0f);
    tetra.getTransform().setScale(0.5f, 0.5f, 0.5f);

    Object cylinder{ Shape::Cylinder() };
    cylinder.getTransform().setPosition(-1.2f, .8f, -4.0f);
    cylinder.getTransform().setRotation(40.0f, 10.0f, 10.0f);
    cylinder.getTransform().setScale(0.75f, 0.6f, 0.75f);

    Object teapot{ "Utah Teapot", MeshImporter::import("assets/teapot.obj") };
    teapot.getTransform().setPosition(0.2f, -1.0f, -4.f);
    teapot.getTransform().setRotation(20.f, 20.0f, 20.f);
    teapot.getTransform().setScale(0.35f, 0.35f, 0.35f);

    Scene scene("MyScene");
    scene.addObject(cube);
    scene.addObject(sphere);
    scene.addObject(tetra);
    scene.addObject(cylinder);
    scene.addObject(teapot);

    return scene;
}

static Camera createCamera() {
    float fovYInDegrees { 45.0f };
    float aspect { static_cast<float>(WIDTH) / HEIGHT };
    float znear { 0.1f };
    float zfar { 100.0f };
    Camera camera { Camera::Perspective(fovYInDegrees, aspect, znear, zfar) };
    return camera;
}

static void render(const Scene& scene, const Camera& camera, const std::string& filename, RendererMode mode = RENDER_SHADER) {
    Renderer renderer(WIDTH, HEIGHT);
    renderer.render(scene, camera, mode);
    renderer.saveImage(filename);
}

int main() {
    const Scene scene = createScene();
    const Camera camera = createCamera();

    render(scene, camera, "output/shaded.ppm");
    render(scene, camera, "output/wireframe.ppm", RENDER_WIREFRAME);
    render(scene, camera, "output/zbuffer.ppm", RENDER_ZBUFFER);
    render(scene, camera, "output/shaded_wireframe.ppm", (RendererMode)(RENDER_SHADER | RENDER_WIREFRAME));

    return 0;
}
