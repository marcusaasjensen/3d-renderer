#include "Mesh.h"

Mesh::Mesh() : vertices(), indices() {}

Mesh::Mesh(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices) 
	: vertices(vertices), indices(indices) {
}
