#pragma once

#include "Canvas.h"
#include "SceneObject.h"
#include "Rasterizer.h"
#include "Matrix4.h"
#include <vector>

class Renderer {
public:
    Renderer(int width, int height);
    Canvas& getCanvas();
    void render(const SceneObject& object, const Matrix4& model, const Matrix4& proj);
    void saveImage(const std::string& filename) const;
private:
    Canvas canvas;
};
