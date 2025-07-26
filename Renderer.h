#pragma once

#include "Canvas.h"
#include "SceneObject.h"
#include "Scene.h"
#include "Rasterizer.h"
#include "Matrix4.h"
#include "Camera.h"
#include <vector>

class Renderer {
public:
    Renderer(int width, int height);

    Canvas& getCanvas();
    void render(const Scene& scene, const Camera& camera);
    void render(const SceneObject& object, const Camera& camera);

    void saveImage(const std::string& filename) const;

private:
    Canvas canvas;
};
