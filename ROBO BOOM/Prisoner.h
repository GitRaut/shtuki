#pragma once
#ifndef PRISONER_H_INCLUDED
#define PRISONER_H_INCLUDED
#include "GAME.h"
class Prisoner{
public:
    Prisoner(int x, int y, int w, int h);
    Prisoner();

    double x_pos, y_pos;
    int speed=1;
    int get_xpos();
    int get_ypos();


    int lives_bar=100;
    void update(SDL_Renderer* renderer);
    int hp_prisoner=100;
    bool svoboda=false;
    bool finel_vert=true;

private:
    SDL_Texture* texture_zalosh;
    double angle;
    double angle2;
    int delta_x, delta_y;
    double offset_x, offset_y;
    int scr_x, scr_y;
    SDL_Surface* image;
    int screen_x;
    int screen_y;
    int x_size, y_size;
    bool textt=true;
};

#endif // PRISONER_H_INCLUDED
