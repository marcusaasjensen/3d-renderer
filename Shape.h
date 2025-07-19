#pragma once
#include "SceneObject.h"

struct Shape {
	static SceneObject Quad(const Transform& transform = Transform{});
	static SceneObject Plane(const Transform& transform = Transform{});
	static SceneObject Cube(const Transform& transform = Transform{});
	static SceneObject Sphere(const Transform& transform);
	static SceneObject Cylinder(const Transform& transform);
	static SceneObject Tetrahedron(const Transform& transform);
};