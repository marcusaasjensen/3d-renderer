#pragma once

#include "Canvas.h"
#include "../scene/Object.h"
#include "../scene/Scene.h"
#include "Rasterizer.h"
#include "../math/Matrix4.h"
#include "Camera.h"
#include <vector>

enum RendererMode {
    RENDER_SHADER = 1 << 0,
    RENDER_WIREFRAME = 1 << 1,
    RENDER_ZBUFFER = 1 << 2
};

class Renderer {
public:

    Renderer(int width, int height);

    Canvas& getCanvas();
    std::vector<Vector3> getProjectedVertices(const Object& object, const Camera& camera);
    void render(const Scene& scene, const Camera& camera, RendererMode mode = RENDER_SHADER);
    void renderWireframe(const Object& object, const Camera& camera);
    void render(const Object& object, const Camera& camera);

    void saveImage(const std::string& filename) const;

private:
    Canvas canvas;
    std::vector<float> zBuffer;

    void clearZBuffer();
};
