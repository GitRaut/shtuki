#ifndef PIXEL_H_INCLUDED
#define PIXEL_H_INCLUDED
#include "header.h"

class Pixel{
public:
    Pixel();
    Pixel(int x, int y, Color color);
    int x_pos;
    int y_pos;
    Color color;
    void set_color(Color _color);
    void update(SDL_Renderer* renderer, int x_sp, int y_sp);
};

#endif // PIXEL_H_INCLUDED
