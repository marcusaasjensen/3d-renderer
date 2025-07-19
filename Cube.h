#pragma once
#include "Mesh.h"
#include "Vector3.h"

struct Cube {
	Transform transform;
	std::vector<Quad> faces;

	Cube();
	Cube(Vector3 position);
};