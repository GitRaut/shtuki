#include "header.h"
#include "Button.h"

Button::Button(){}

Button::Button(int x, int y, int w, int h, SDL_Texture* active, SDL_Texture* unactive){
    x_pos = x;
    y_pos = y;
    x_size = w;
    y_size = h;
    on = active;
    off = unactive;
    selected = false;
}

bool Button::is_selected(){
    int x_mouse, y_mouse;
    SDL_GetMouseState(&x_mouse, &y_mouse);
    if((x_mouse >= x_pos && x_mouse <= x_pos + x_size) && (y_mouse >= y_pos && y_mouse <= y_pos + y_size)){
        return true;
    }
    return false;
}

bool Button::click(){
    if(is_selected() && GetAsyncKeyState(VK_LBUTTON))
        return true;
    return false;
}

void Button::update(SDL_Renderer* renderer){
    if(is_selected()){
        selected = true;
        SDL_Rect rect = {x_pos, y_pos,  x_size, y_size};
        SDL_RenderCopy(renderer, on, NULL, &rect);
    }
    else{
        selected = false;
        SDL_Rect rect = {x_pos, y_pos, x_size, y_size};
        SDL_RenderCopy(renderer, off, NULL, &rect);
    }
}
