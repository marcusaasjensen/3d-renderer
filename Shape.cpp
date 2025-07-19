#include "Shape.h"

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
            // Front face
            Vertex(-0.5f, -0.5f,  0.5f),
            Vertex(0.5f, -0.5f,  0.5f),
            Vertex(0.5f,  0.5f,  0.5f),
            Vertex(-0.5f,  0.5f,  0.5f),

            // Back face
            Vertex(-0.5f, -0.5f, -0.5f),
            Vertex(0.5f, -0.5f, -0.5f),
            Vertex(0.5f,  0.5f, -0.5f),
            Vertex(-0.5f,  0.5f, -0.5f)
        },
        {
            // Front
            0, 1, 2,  0, 2, 3,
            // Right
            1, 5, 6,  1, 6, 2,
            // Back
            5, 4, 7,  5, 7, 6,
            // Left
            4, 0, 3,  4, 3, 7,
            // Top
            3, 2, 6,  3, 6, 7,
            // Bottom
            4, 5, 1,  4, 1, 0
        }
    });
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
