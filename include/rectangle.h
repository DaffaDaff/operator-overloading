#pragma once

#include <iostream>

#include "include/point.h"

class rectangle{
    private:
        point center;
        int width;
        int height;
        char symbol;
    public:
        rectangle(point _center, int _width, int _height, char _symbol) { center = _center; width = _width; height = _height; symbol = _symbol; };

        float GetX() { return center.x; };
        float GetY() { return center.y; };

        int GetWidth() { return width; };
        int GetHeight() { return height; };

        char GetSymbol() { return symbol; };

        float GetXMin() { return center.y - (height / 2.f); };
        float GetXMax() { return center.y + (height / 2.f); };

        float GetYMin() { return center.y - (width / 2.f); };
        float GetYMax() { return center.y + (width / 2.f); };

};