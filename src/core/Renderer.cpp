#include "Renderer.h"

Renderer::Renderer(int width, int height) : canvas{ width, height }, zBuffer{ std::vector<float>(width * height, std::numeric_limits<float>::infinity()) } {}

Canvas& Renderer::getCanvas() {
    return canvas;
}

std::vector<Vector3> Renderer::getProjectedVertices(const Object& object, const Camera& camera) {
    std::vector<Vector3> projected;

    const auto& mesh = object.getMesh();
    const Matrix4& model = object.getTransform().getModel();
    const Matrix4& projection = camera.getProjection();
    const Matrix4& view = camera.getView();

    for (size_t i = 0; i < mesh.indices.size(); i += 3) {
        bool skip = false;
        for (int j = 0; j < 3; ++j) {
            int idx = mesh.indices[i + j];
            Vector4 v(mesh.vertices[idx].position);
            v = projection * (view * (model * v));

            if (v.w <= 0.0f) {
                skip = true;
                break;
            }

            if (v.w != 0.0f) {
                v.x /= v.w;
                v.y /= v.w;
                v.z /= v.w;
            }

            if (skip) continue;

            int screenX = static_cast<int>((v.x * 0.5f + 0.5f) * canvas.getWidth());
            int screenY = static_cast<int>((1.0f - (v.y * 0.5f + 0.5f)) * canvas.getHeight());
            projected.emplace_back((float)screenX, (float)screenY, v.z);
        }
    }

    return projected;
}


void Renderer::render(const Object& object, const Camera& camera) {
    auto vertices = getProjectedVertices(object, camera);

    for (size_t i = 0; i < vertices.size(); i += 3) {
        Rasterizer::fillTriangle(vertices[i], vertices[i + 1], vertices[i + 2], canvas, zBuffer);
    }
}

void Renderer::renderWireframe(const Object& object, const Camera& camera) {
    auto vertices = getProjectedVertices(object, camera);

    for (size_t i = 0; i < vertices.size(); i += 3) {
        Rasterizer::drawTriangle(vertices[i], vertices[i + 1], vertices[i + 2], canvas);
    }
}

void Renderer::render(const Scene& scene, const Camera& camera, RendererMode mode) {
    canvas.clear();
    clearZBuffer();

    auto& objects = scene.getObjects();

    if (mode & RENDER_SHADER)
        for (const Object& object : objects)
            render(object, camera);

    if(mode & RENDER_WIREFRAME)
        for (const Object& object : objects)
            renderWireframe(object, camera);

    if (mode & RENDER_ZBUFFER) {
        render(scene, camera, RENDER_SHADER);
        Rasterizer::drawZBuffer(zBuffer, canvas);
    }
}


void Renderer::saveImage(const std::string& filename) const {
    canvas.saveToPPM(filename);
}

void Renderer::clearZBuffer() {
    std::fill(zBuffer.begin(), zBuffer.end(), std::numeric_limits<float>::infinity());
}
