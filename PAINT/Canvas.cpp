#include "header.h"
#include "Canvas.h"

Canvas::Canvas(){};

void Canvas::fill_grid(int w, int h){
    vector <vector <Pixel>>().swap(grid);
    Color color(255, 255, 255, 255);
    for(int y = 0; y < h; y++){
        vector <Pixel> el;
        for(int x = 0; x < w; x++){
            Pixel pixel(x, y, color);
            el.push_back(pixel);
        }
        grid.push_back(el);
    }
}

Canvas::Canvas(int x, int y, int w, int h, Color _color){
    x_pos = x;
    y_pos = y;
    x_size = w;
    y_size = h;
    color = _color;
    fill_grid(w / pixel_size, h / pixel_size);
}

void Canvas::update(SDL_Renderer* renderer, Brush brush){
    int x_mouse, y_mouse;
    SDL_GetMouseState(&x_mouse, &y_mouse);
    if((x_mouse > x_pos && y_mouse > y_pos) && (x_mouse < x_pos + x_size && y_mouse < y_pos + y_size)){
        if(GetAsyncKeyState(VK_LBUTTON)){
            int x = (x_mouse - x_pos) / pixel_size;
            int y = (y_mouse - y_pos) / pixel_size;
            for(int iy = 0; iy < brush.brush_size; iy++){
                for(int ix = 0; ix < brush.brush_size; ix++){
                    if(x + ix >= grid[0].size() && y + iy >= grid.size())
                        grid[y][x].set_color(brush.color);
                    else if(x + ix >= grid[0].size() && y + iy < grid.size())
                        grid[y + iy][x].set_color(brush.color);
                    else if(x + ix < grid[0].size() && y + iy >= grid.size())
                        grid[y][x + ix].set_color(brush.color);
                    else
                        grid[y + iy][x + ix].set_color(brush.color);
                }
            }
        }
    }
    SDL_Rect rect = {x_pos, y_pos, x_size, y_size};
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &rect);
    for(int y = 0; y < grid.size(); y++){
        for(int x = 0; x < grid[0].size(); x++){
            grid[y][x].update(renderer, x_pos, y_pos);
        }
    }
}

void Canvas::set_color(Color _color){
    color = _color;
}
