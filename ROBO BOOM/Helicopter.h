#ifndef HELICOPTER_H_INCLUDED
#define HELICOPTER_H_INCLUDED
#include "GAME.h"
class Helicopter{
public:

    Helicopter(int x, int y, int w, int h);
    Helicopter();

    double x_pos, y_pos;
    int speed;


    void update(SDL_Renderer* renderer);

private:
    Mix_Chunk* fly = Mix_LoadWAV("Sounds\\helicopter.wav");
    Mix_Music* win = Mix_LoadMUS("Sounds\\win.wav");
    bool texxt=true;
    double angle_vint=0;
    int time_polet=-1;
    bool polet=false;
    double angle;
    int delta_x, delta_y;
    double offset_x, offset_y;
    int screen_x, screen_y;
    int x_size, y_size;
    SDL_Surface* image;
};

#endif // HELICOPTER_H_INCLUDED
