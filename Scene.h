#pragma once

#include "SceneObject.h"
#include <vector>

class Scene {
private:
    std::vector<SceneObject> objects;
    std::string name;
public:
    explicit Scene(const std::string& name);

    void addObject(const SceneObject& object);
    const std::vector<SceneObject>& getObjects() const;
    void setName(const std::string name);
    std::string getName() const;
};
