#pragma once
#include "Mesh.h"
#include "Transform.h"

class Quad {
private:
	Mesh mesh;
	Transform transform;

public:
	Quad();
	Quad(const Transform& transform);
};
