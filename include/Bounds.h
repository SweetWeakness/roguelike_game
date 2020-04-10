#ifndef GAME_BOUNDS_H
#define GAME_BOUNDS_H


class Bounds {
private:
    int x1, y1, x2, y2;

public:
    explicit Bounds();
    Bounds(int ax, int ay, int bx, int by);
    bool isVertBelong(int x, int y);
};


#endif //GAME_BOUNDS_H
