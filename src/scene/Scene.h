#pragma once

#include "Object.h"
#include <vector>

class Scene {
private:
    std::vector<Object> objects;
    std::string name;
public:
    explicit Scene(const std::string& name);

    void addObject(const Object& object);
    const std::vector<Object>& getObjects() const;
    void setName(const std::string name);
    std::string getName() const;
};
