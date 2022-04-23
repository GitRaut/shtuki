#ifndef BRUSH_H_INCLUDED
#define BRUSH_H_INCLUDED
#include "header.h"

class Brush{
public:
    Brush();
    Brush(Color _color);
    string tag = "draw";
    int brush_size = 1;
    int timer = 80;
    Color color;

    void change_color(
        SDL_Renderer* renderer,
        Image img,
        int x, int y,
        int scale);
    void change_size(int _size);
};

#endif // BRUSH_H_INCLUDED
