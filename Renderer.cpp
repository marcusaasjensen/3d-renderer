#include "Renderer.h"

Renderer::Renderer(int width, int height) : canvas(width, height) {}

Canvas& Renderer::getCanvas() {
    return canvas;
}

void Renderer::render(const SceneObject& object, const Camera& camera) {
    const auto& mesh = object.getMesh();
    const Matrix4& model = object.getTransform().getModel();

    for (size_t i = 0; i < mesh.indices.size(); i += 3) {
        Vector4 screenVerts[3];

        for (int j = 0; j < 3; ++j) {
            int idx = mesh.indices[i + j];
            Vector4 v(mesh.vertices[idx].position);
            v = camera.getProjection() * (model * v);

            if (v.w != 0.0f) {
                v.x /= v.w;
                v.y /= v.w;
                v.z /= v.w;
            }

            int screenX = static_cast<int>((v.x * 0.5f + 0.5f) * canvas.getWidth());
            int screenY = static_cast<int>((1.0f - (v.y * 0.5f + 0.5f)) * canvas.getHeight());
            screenVerts[j] = Vector4((float)screenX, (float)screenY, 0.0f, 1.0f);
        }

        Rasterizer::drawLine((int)screenVerts[0].x, (int)screenVerts[0].y,
            (int)screenVerts[1].x, (int)screenVerts[1].y,
            canvas);
        Rasterizer::drawLine((int)screenVerts[1].x, (int)screenVerts[1].y,
            (int)screenVerts[2].x, (int)screenVerts[2].y,
            canvas);
        Rasterizer::drawLine((int)screenVerts[2].x, (int)screenVerts[2].y,
            (int)screenVerts[0].x, (int)screenVerts[0].y,
            canvas);
    }
}

void Renderer::render(const Scene& scene, const Camera& camera) {
    canvas.clear();

    for (const SceneObject& object : scene.getObjects()) {
        render(object, camera);
    }
}

void Renderer::saveImage(const std::string& filename) const {
    canvas.saveToPPM(filename);
}
