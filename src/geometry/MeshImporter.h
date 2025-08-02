#pragma once

#include "Mesh.h"

class MeshImporter {
public:
	static Mesh import(const std::string& filename);
};