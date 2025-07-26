#include "Shape.h"
#include "Math.h"

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
    const int stacks { 16 };
    const int slices { 32 };
    const float radius { 0.5f };

    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;

    for (int i = 0; i <= stacks; ++i) {
        float v { float(i) / stacks };
        float phi { v * Math::PI };

        for (int j = 0; j <= slices; ++j) {
            float u{ float(j) / slices };
            float theta{ u * 2.0f * Math::PI };

            float x{ radius * std::sin(phi) * std::cos(theta) };
            float y{ radius * std::cos(phi) };
            float z{ radius * std::sin(phi) * std::sin(theta) };

            vertices.emplace_back(x, y, z);
        }
    }

    for (int i = 0; i < stacks; ++i) {
        for (int j = 0; j < slices; ++j) {
            int first { i * (slices + 1) + j };
            int second { first + slices + 1 };

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

SceneObject Shape::Tetrahedron(const Transform& transform) {
    std::vector<Vertex> vertices = {
        Vertex(.5f,  .5f,  .5f),
        Vertex(-.5f, -.5f,  .5f),
        Vertex(-.5f,  .5f, -.5f),
        Vertex(.5f, -.5f, -.5f)
    };

    std::vector<unsigned int> indices = {
        0, 1, 2,
        0, 3, 1,
        0, 2, 3,
        1, 3, 2
    };

    return SceneObject("Tetrahedron", transform, { vertices, indices });
}

SceneObject Shape::Cylinder(const Transform& transform) {
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
    const int segments = 32;
    const float height = 1.0f; 
    const float radius = 0.5f;

    for (int i = 0; i <= segments; ++i) {
        float angle = (2.0f * Math::PI * i) / segments;
        float x = radius * std::cos(angle);
        float z = radius * std::sin(angle);

        vertices.emplace_back(x, -height * 0.5f, z);
        vertices.emplace_back(x, height * 0.5f, z);
    }

    int bottomCenterIndex = (int)vertices.size();
    vertices.emplace_back(0, -height * 0.5f, 0);

    int topCenterIndex = (int)vertices.size();
    vertices.emplace_back(0, height * 0.5f, 0);

    for (int i = 0; i < segments; ++i) {
        int bottomCurrent = i * 2;
        int topCurrent = bottomCurrent + 1;
        int bottomNext = ((i + 1) % segments) * 2;
        int topNext = bottomNext + 1;

        indices.push_back(bottomCurrent);
        indices.push_back(topCurrent);
        indices.push_back(topNext);

        indices.push_back(bottomCurrent);
        indices.push_back(topNext);
        indices.push_back(bottomNext);
    }

    for (int i = 0; i < segments; ++i) {
        int curr = i * 2;
        int next = ((i + 1) % segments) * 2;

        indices.push_back(bottomCenterIndex);
        indices.push_back(next);
        indices.push_back(curr);
    }

    for (int i = 0; i < segments; ++i) {
        int curr = i * 2 + 1;
        int next = ((i + 1) % segments) * 2 + 1;

        indices.push_back(topCenterIndex);
        indices.push_back(curr);
        indices.push_back(next);
    }

    return SceneObject("Cylinder", transform, { vertices, indices });
}

