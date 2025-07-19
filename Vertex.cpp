#include "Vertex.h"

Vertex::Vertex()
    : position{}, normal{}, color{} {
}

Vertex::Vertex(const Vector3& position)
    : position{ position }, normal{}, color{} {
}

Vertex::Vertex(const Vector3& position, const Color& color)
    : position{ position }, normal{}, color(color) {
}

Vertex::Vertex(const Vector3& position, const Vector3& normal)
    : position{ position }, normal{ normal }, color{} {
}

Vertex::Vertex(const Vector3& position, const Vector3& normal, const Color& color)
    : position{ position }, normal{ normal }, color{ color } {
}

Vertex::Vertex(float x, float y, float z)
    : position{ x, y, z }, normal{}, color{} {
}

Vertex::Vertex(float x, float y, float z, float nx, float ny, float nz, const Color& color)
    : position{ x, y, z }, normal{ nx, ny, nz }, color{ color } {
}
