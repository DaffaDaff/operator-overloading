#include "include/rectangle.h"

rectangle::rectangle(point _center, int _width, int _height, char _symbol, bool _isFill){
    center = _center; 
    width = _width; 
    height = _height; 
    symbol = _symbol; 
    isFill = _isFill;

    UpdateXMax();
    UpdateXMin();
    UpdateYMax();
    UpdateYMin();
}