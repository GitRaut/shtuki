#include "header.h"
#include "Pixel.h"

Pixel::Pixel(){}
Pixel::Pixel(int x, int y, Color _color){
    x_pos = x;
    y_pos = y;
    color = _color;
};

void Pixel::set_color(Color _color){
    color = _color;
}

void Pixel::update(SDL_Renderer* renderer, int x_sp, int y_sp){
    SDL_Rect rect = {
        x_pos * pixel_size + x_sp,
        y_pos * pixel_size + y_sp,
        pixel_size, pixel_size};

    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &rect);
}
