#include <vector>
#include "Cube.h"


Cube::Cube() {
	std::vector<Vertex> vertices {
		Vertex(0,0,0),
		Vertex(1,0,0),
		Vertex(1,1,0),
	};
}