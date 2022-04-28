#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

#include <iostream>

#include "include/utils.h"

class rectangle{
    private:
        point center;
        int width;
        int height;
        char symbol;

        float xMin;
        float xMax;
        float yMin;
        float yMax;

        bool isFill;
    public:
        rectangle(point _center, int _width, int _height, char _symbol, bool _isFill);

        void SetWidth(int value) { width = value; };
        void SetHeight(int value) { height = value; };

        void SetFill(bool value) { isFill = value; };

        float GetX() { return center.x; };
        float GetY() { return center.y; };

        int GetWidth() { return width; };
        int GetHeight() { return height; };

        char GetSymbol() { return symbol; };

        float GetXMin() { return xMin; };
        float GetXMax() { return xMax; };
        float GetYMin() { return yMin; };
        float GetYMax() { return yMax; };

        bool GetFill() { return isFill; }

        void UpdateXMin() { xMin =  center.y - (width / 2.f); };
        void UpdateXMax() { xMax = center.y + (width / 2.f); };

        void UpdateYMin() { yMin = center.y - (height / 2.f); };
        void UpdateYMax() { yMax = center.y + (height / 2.f); };



};

#endif