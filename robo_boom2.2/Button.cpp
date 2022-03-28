#include "GAME.h"
#include "Button.h"

Button::Button(SDL_Texture* off, SDL_Texture* on, int x, int y, int w, int h, int act_w, int act_h, int del){
    active = on;
    un_active = off;
    x_pos = x;
    y_pos = y;
    x_size = w;
    y_size = h;
    x_size_act = act_w;
    y_size_act = act_h;
    x_act = x_pos - (x_size_act - x_size) / 2;
    y_act = y_pos - (y_size_act - y_size) / 2;
    delay = del;
}
Button::Button(){}

void Button::update(SDL_Renderer* renderer){
    if(is_selected(x_pos, y_pos, x_size, y_size)){
        if(!selected)Mix_PlayChannel(0, on_hover, 0);
        selected = true;
        SDL_Rect rect = {x_act, y_act,  x_size_act, y_size_act};
        SDL_RenderCopy(renderer, active, NULL, &rect);
    }
    else{
        selected = false;
        SDL_Rect rect = {x_pos, y_pos, x_size, y_size};
        SDL_RenderCopy(renderer, un_active, NULL, &rect);
    }
}

bool Button::click(){
    if(timer > 0)timer--;
    if(is_selected(x_pos, y_pos, x_size, y_size) && GetAsyncKeyState(VK_LBUTTON) < 0 && timer == 0){
        Mix_PlayChannel(0, on_hover, 0);
        timer = delay;
        return true;
    }
    return false;
}

