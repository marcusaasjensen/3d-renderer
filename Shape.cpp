#include "Shape.h"
constexpr float PI = 3.14159265358979323846f;

SceneObject Shape::Quad(const Transform& transform) {
    return SceneObject("Quad", transform, {
        {
            Vertex(0, 0, 0),
            Vertex(1, 0, 0),
            Vertex(0, 1, 0),
            Vertex(1, 1, 0)
        },
        {
            0, 2, 1,
            1, 2, 3
        }
    });
}

SceneObject Shape::Cube(const Transform& transform) {
    return SceneObject("Cube", transform, {
        {
            Vertex(-0.5f, -0.5f,  0.5f),
            Vertex(0.5f, -0.5f,  0.5f),
            Vertex(0.5f,  0.5f,  0.5f),
            Vertex(-0.5f,  0.5f,  0.5f),

            Vertex(-0.5f, -0.5f, -0.5f),
            Vertex(0.5f, -0.5f, -0.5f),
            Vertex(0.5f,  0.5f, -0.5f),
            Vertex(-0.5f,  0.5f, -0.5f)
        },
        {
            0, 1, 2,  0, 2, 3,

            1, 5, 6,  1, 6, 2,

            5, 4, 7,  5, 7, 6,

            4, 0, 3,  4, 3, 7,

            3, 2, 6,  3, 6, 7,

            4, 5, 1,  4, 1, 0
        }
    });
}

SceneObject Shape::Sphere(const Transform& transform) {
    const int stacks = 16;
    const int slices = 32;
    const float radius = 0.5f;

    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;

    for (int i = 0; i <= stacks; ++i) {
        float v = float(i) / stacks;
        float phi = v * PI;

        for (int j = 0; j <= slices; ++j) {
            float u = float(j) / slices;
            float theta = u * 2.0f * PI;

            float x = radius * std::sin(phi) * std::cos(theta);
            float y = radius * std::cos(phi);
            float z = radius * std::sin(phi) * std::sin(theta);

            vertices.emplace_back(x, y, z);
        }
    }

    for (int i = 0; i < stacks; ++i) {
        for (int j = 0; j < slices; ++j) {
            int first = i * (slices + 1) + j;
            int second = first + slices + 1;

            indices.push_back(first);
            indices.push_back(second);
            indices.push_back(first + 1);

            indices.push_back(second);
            indices.push_back(second + 1);
            indices.push_back(first + 1);
        }
    }

    return SceneObject("Sphere", transform, { vertices, indices });
}


SceneObject Shape::Plane(const Transform& transform) {
    Mesh mesh = {
        {
            Vertex(-0.5f, 0.0f, -0.5f),
            Vertex(0.5f, 0.0f, -0.5f),
            Vertex(-0.5f, 0.0f,  0.5f),
            Vertex(0.5f, 0.0f,  0.5f)
        },
        {
            0, 1, 2,
            2, 1, 3
        }
    };

    return SceneObject("Plane", transform, mesh);
}
