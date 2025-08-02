#include "Object.h"
#include "Scene.h"

Object::Object() : name{ "Object" }, transform{}, mesh{} {}

Object::Object(const std::string& name, const Mesh& mesh) : name{ name }, transform{}, mesh{ mesh }  {
}

Object::Object(const std::string& name, const Transform& transform, const Mesh& mesh) :
	name{ name }, 
	transform{ transform }, 
	mesh{ mesh } {
}

void Object::setName(const std::string name) {
	this->name = name;
}

std::string Object::getName() const {
	return name;
}

void Object::setTransform(const Transform& transform) {
	this->transform = transform;
}

Transform& Object::getTransform() {
	return transform;
}

const Transform& Object::getTransform() const {
	return transform;
}

const Mesh& Object::getMesh() const {
	return mesh;
}
