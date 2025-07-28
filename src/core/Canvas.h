#pragma once

#include <vector>
#include <string>

class Canvas {
public:
    Canvas(int width, int height);
    void setPixel(int x, int y, unsigned char r, unsigned char g, unsigned char b);
    void clear();
    void saveToPPM(const std::string& filename) const;

    int getWidth() const { return width; }
    int getHeight() const { return height; }
private:
    int width, height;
    std::vector<unsigned char> buffer;
};
