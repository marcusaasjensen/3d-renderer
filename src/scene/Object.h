#pragma once
#include <string>
#include "Transform.h"
#include "../geometry/Mesh.h"
#include "../math/Matrix4.h"

class Object {
private:
	std::string name;
	Transform transform;
	Mesh mesh;

public:
	Object();
	~Object() = default;
	Object(const Object& other) = default;
	Object(const std::string& name, const Mesh& mesh);
	Object(const std::string& name, const Transform& transform, const Mesh& mesh);

public:
	void setName(const std::string name);
	std::string getName() const;

	void setTransform(const Transform& transform);
	Transform& getTransform();
	const Transform& getTransform() const;

	const Mesh& getMesh() const;
};