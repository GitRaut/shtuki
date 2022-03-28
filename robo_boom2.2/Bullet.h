#pragma once
#ifndef BULLET_H_INCLUDED
#define BULLET_H_INCLUDED
#include "GAME.h"
#include "Bullet.h"

class Bullet{
public:
    Bullet(int x, int y,int x2,int y2, int width, int height, SDL_Texture* tex, int speed,int type);
    ~Bullet(){}

    void move_bullet(SDL_Renderer* renderer);



    void get_size(int &width, int &height);
    void set_size(int width, int height);

    void get_position(int &x, int &y);
    void set_position(int x, int y);

    void set_image(SDL_Surface* img);
    void set_texture(SDL_Texture* tex);

    int get_xpos();
    int get_ypos();

    int get_width();
    int get_height();

    bool live;


private:
    Mix_Chunk* boom = Mix_LoadWAV("Sounds\\rpg_boom.wav");
    Mix_Chunk* recos = Mix_LoadWAV("Sounds\\recoshet.wav");
    float k;
    int x_smesheniye;
    double x_pos;
    double y_pos;
    int x2_pos;
    int y2_pos;
    int bullet_speed;

    int type_bullet;

    int screen_x;
    int screen_y;

    int x_size;
    int y_size;
    bool quit = false;
    double angle;
    double angle2;
    SDL_Surface* image;
    SDL_Texture* texture;
};

#endif // BULLET_H_INCLUDED
