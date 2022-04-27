#pragma once

#include <iostream>
#include <iomanip>
#include <vector>
#include <math.h>
#include <string.h>
#include <cstdlib>

#include "include/utils.h"
#include "include/rectangle.h"
#include "include/point.h"

using namespace std;

struct worldData{
    vector<rectangle> rectangles;

    int offsetX = 0;
    int offsetY = 0;
};

namespace coordinateSystem{
    void Draw(worldData* data);
};