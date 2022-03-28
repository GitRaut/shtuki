#pragma once
#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED
#include "GAME.h"

class Button{
private:
    Mix_Chunk* on_hover = Mix_LoadWAV("Sounds\\button_1.wav");
    bool selected;
    SDL_Texture* active;
    SDL_Texture* un_active;
    int timer = 0;
    int delay;

public:
    int x_pos, y_pos;
    int x_size, y_size, x_act, y_act;
    int x_size_act, y_size_act;
    Button(SDL_Texture* off, SDL_Texture* on, int x, int y, int w, int h, int act_w, int act_h, int del);
    Button();
    void update(SDL_Renderer* renderer);
    bool click();
};

#endif // BUTTON_H_INCLUDED
