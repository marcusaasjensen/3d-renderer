#pragma once
#include <vector>
#include "Vertex.h"

struct Mesh {
	std::vector<Vertex> vertices;
	std::vector<unsigned int> indices;

	Mesh();
	Mesh(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices);
};