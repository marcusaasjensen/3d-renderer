#pragma once
#include "SceneObject.h"
#include <numbers>

class Shape {
public:
	static SceneObject Quad(const Transform& transform = Transform{});
	static SceneObject Plane(const Transform& transform = Transform{});
	static SceneObject Cube(const Transform& transform = Transform{});
	static SceneObject Sphere(const Transform& transform = Transform{});
	static SceneObject Cylinder(const Transform& transform = Transform{});
	static SceneObject Tetrahedron(const Transform& transform = Transform{});
};