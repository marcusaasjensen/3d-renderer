#pragma once
#include "../scene/Object.h"
#include <numbers>

class Shape {
public:
	static Object Quad(const Transform& transform = Transform{});
	static Object Plane(const Transform& transform = Transform{});
	static Object Cube(const Transform& transform = Transform{});
	static Object Sphere(const Transform& transform = Transform{});
	static Object Cylinder(const Transform& transform = Transform{});
	static Object Tetrahedron(const Transform& transform = Transform{});
};