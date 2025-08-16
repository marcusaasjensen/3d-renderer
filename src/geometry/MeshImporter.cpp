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
            std::vector<std::string> tokens;
            std::string token;
            while (iss >> token) {
                tokens.push_back(token);
            }

            auto parseIndex = [](const std::string& tok) {
                std::istringstream ss(tok);
                std::string indexStr;
                std::getline(ss, indexStr, '/');
                return std::stoi(indexStr) - 1;
                };

            for (size_t i = 1; i + 1 < tokens.size(); i++) {
                mesh.indices.push_back(parseIndex(tokens[0]));
                mesh.indices.push_back(parseIndex(tokens[i]));
                mesh.indices.push_back(parseIndex(tokens[i + 1]));
            }
        }


    }

    return mesh;
}
