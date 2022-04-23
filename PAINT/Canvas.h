#ifndef CANVAS_H_INCLUDED
#define CANVAS_H_INCLUDED
#include "header.h"

using std::vector;
using std::string;

class Canvas{
private:
    int x_pos;
    int y_pos;
    int x_size;
    int y_size;
    Color color;
    void fill_grid(int w, int h);

public:
    Canvas();
    Canvas(int x, int y, int w, int h, Color _color);
    vector <vector <Pixel>> grid;
    void update(SDL_Renderer* renderer, Brush brush);
    void set_color(Color _color);
};

#endif // CANVAS_H_INCLUDED
