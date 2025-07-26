#pragma once
#include <string>
#include "Transform.h"
#include "Mesh.h"
#include "Matrix4.h"

class SceneObject {
private:
	std::string name;
	Transform transform;
	Mesh mesh;

public:
	SceneObject();
	~SceneObject() = default;
	SceneObject(const SceneObject& other) = default;
	SceneObject(const std::string& name, const Transform& transform, const Mesh& mesh);

public:
	void setName(const std::string name);
	std::string getName() const;

	void setTransform(const Transform& transform);
	Transform& getTransform();
	const Transform& getTransform() const;

	const Mesh& getMesh() const;
};