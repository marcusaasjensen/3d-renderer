#include <vector>
#include "Quad.h"

Quad::Quad() : mesh {
    {
        Vertex(0, 0, 0),
        Vertex(1, 0, 0),
        Vertex(0, 1, 0),
        Vertex(1, 1, 0)
    },
    {
        0, 1, 2,
        2, 1, 3
    }
} {
}
