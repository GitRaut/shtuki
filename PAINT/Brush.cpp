#include "header.h"
#include "Brush.h"

Brush::Brush(){}

Brush::Brush(Color _color){
    color = _color;
}

void Brush::change_color(SDL_Renderer* renderer, Image img, int x, int y, int scale){
    if(tag == "draw"){
        int x_mouse, y_mouse;
        SDL_GetMouseState(&x_mouse, &y_mouse);
        if(x_mouse >= x && y_mouse >= y && x_mouse <= x + scale && y_mouse <= y + scale){
            color = img.getPixel(x_mouse - x, y_mouse - y);
            render_texture(
                renderer,
                bord,
                x_mouse - 2,
                y_mouse - 2,
                24, 24);
            SDL_Rect rect = {x_mouse, y_mouse, 20, 20};
            SDL_SetRenderDrawColor(
                renderer,
                color.r,
                color.g,
                color.b,
                color.a);
            SDL_RenderFillRect(renderer, &rect);
        }
    }
}

void Brush::change_size(int _size){
    if(GetAsyncKeyState(VK_UP) && timer <= 0){
        timer = 80;
        brush_size += _size;
    }
    if(GetAsyncKeyState(VK_DOWN) && timer <= 0 && brush_size > 1){
        timer = 80;
        brush_size  -= _size;
    }
}
