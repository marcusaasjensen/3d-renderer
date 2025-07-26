#include "SceneObject.h"
#include "Scene.h"

SceneObject::SceneObject() : name{ "SceneObject" }, transform{}, mesh{} {}
SceneObject::SceneObject(const std::string& name, const Transform& transform, const Mesh& mesh) : 
	name{ name }, 
	transform{ transform }, 
	mesh{ mesh } {
}

void SceneObject::setName(const std::string name) {
	this->name = name;
}

std::string SceneObject::getName() const {
	return name;
}

void SceneObject::setTransform(const Transform& transform) {
	this->transform = transform;
}

Transform& SceneObject::getTransform() {
	return transform;
}

const Transform& SceneObject::getTransform() const {
	return transform;
}

const Mesh& SceneObject::getMesh() const {
	return mesh;
}
