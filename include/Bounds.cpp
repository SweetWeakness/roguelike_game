#include "Bounds.h"


Bounds::Bounds() : x1(0), x2(0), y1(0), y2(0) {}

Bounds::Bounds(int ax, int ay, int bx, int by)  : x1(ax), x2(bx), y1(ay), y2(by) {}

bool Bounds::isVertBelong(int x, int y){
    return (x1 <= x && x <= x2 && y1 <= y && y <= y2);
}