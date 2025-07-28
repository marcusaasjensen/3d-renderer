#include "Scene.h"

Scene::Scene(const std::string& name) : objects{}, name {name} {
}

void Scene::addObject(const Object& object) {
    objects.push_back(object);
}

const std::vector<Object>& Scene::getObjects() const {
    return objects;
}

void Scene::setName(const std::string name) {
	this->name = name;
}

std::string Scene::getName() const {
	return name;
}
