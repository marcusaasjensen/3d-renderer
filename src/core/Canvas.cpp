#include "Canvas.h"
#include <fstream>
#include <iostream>

Canvas::Canvas(int w, int h) : width(w), height(h), buffer(w* h * 3, 0) {}

void Canvas::setPixel(int x, int y, unsigned char r, unsigned char g, unsigned char b) {
    if (x < 0 || x >= width || y < 0 || y >= height) return;
    int idx = (y * width + x) * 3;
    buffer[idx] = r;
    buffer[idx + 1] = g;
    buffer[idx + 2] = b;
}

void Canvas::clear() {
    std::fill(buffer.begin(), buffer.end(), 0);
}

void Canvas::saveToPPM(const std::string& filename) const {
    std::ofstream out(filename);
    out << "P3\n" << width << " " << height << "\n255\n";
    for (size_t i = 0; i < buffer.size(); i += 3) {
        out << (int)buffer[i] << " " << (int)buffer[i + 1] << " " << (int)buffer[i + 2] << "\n";
    }
    out.close();
    std::cout << "Wrote " << filename << std::endl;
}
