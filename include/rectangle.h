#pragma once

#include <iostream>

#include "include/point.h"

class rectangle{
    private:
        point center;
        int width;
        int height;
    public:
        rectangle(point _center, int _width, int _height) { center = _center; width = _width; height = _height; }
};