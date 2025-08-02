#include <fstream>
#include "MeshImporter.h"

#include <sstream>
#include <iostream>
#include <string>

Mesh MeshImporter::import(const std::string& filename) {
    Mesh mesh;

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open mesh file: " << filename << std::endl;
        return mesh;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string prefix;
        iss >> prefix;

        if (prefix == "v") {
            float x, y, z;
            iss >> x >> y >> z;
            mesh.vertices.emplace_back(x, y, z);
        }
        else if (prefix == "f") {
            int a, b, c;
            iss >> a >> b >> c;
            mesh.indices.push_back(a - 1);
            mesh.indices.push_back(b - 1);
            mesh.indices.push_back(c - 1);
        }
    }

    return mesh;
}
