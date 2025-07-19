#include "SceneObject.h"

SceneObject::SceneObject() : name{ "SceneObject" }, transform{}, mesh{} {}
SceneObject::SceneObject(const std::string& name, const Transform& transform, const Mesh& mesh) : 
	name{ name }, 
	transform{ transform }, 
	mesh{ mesh } {
}