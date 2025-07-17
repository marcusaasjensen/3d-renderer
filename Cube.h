#pragma once
#include "Mesh.h"
#include "Vector3.h"

struct Cube {
	Mesh mesh;
	Vector3 position;

	Cube();
	Cube(Vector3 position);
};