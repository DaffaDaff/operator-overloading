#pragma once

#include <iostream>
#include <windows.h>

#include "include/utils.h"
#include "include/coordinateSystem.h"

using namespace std;

namespace input{
    void MainMenu(worldData* data);
    void Graph(worldData* data);
    
    void ShowGraphSelection();
};