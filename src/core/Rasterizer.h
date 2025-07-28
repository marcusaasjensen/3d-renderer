#pragma once

#include <vector>
#include "Canvas.h"

class Rasterizer {
public:
    static void drawLine(int x0, int y0, int x1, int y1, Canvas& fb);
};