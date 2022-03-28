#pragma once
#ifndef BOT_TANK_H_INCLUDED
#define BOT_TANK_H_INCLUDED
#include "GAME.h"
class Bot_tank{
public:
    Bot_tank(int x, int y, int width, int height, int speed, int m);
    Bot_tank();

    void move_Bot_tank(SDL_Renderer* renderer);

    int marshrut;

    void get_size(int &width, int &height);
    void set_size(int width, int height);

    void get_position(int &x, int &y);
    void set_position(int x, int y);

    void set_image(SDL_Surface* img);
    void set_texture(SDL_Texture* tex);
    int way_bot=0;

    int get_xpos();
    int get_ypos();
    int k_smesh=0;

    int get_width();
    int get_height();

    bool live;
    int life_bar_bot=200;
    int time_nul=0;

    bool null_com=false;
    int time_shield_anim=0;

    int shield_prochnost=5;
    bool shield=true;


private:
    Mix_Chunk* laser = Mix_LoadWAV("Sounds\\laser.wav");
    Mix_Chunk* boom = Mix_LoadWAV("Sounds\\rpg_boom.wav");
    int g;
    float k;
    int x_smesheniye;
    double x_pos;
    double y_pos;
    double x2_pos;
    double y2_pos;
    int screen_x;
    int screen_y;
    double x2_pos_player_old;
    double y2_pos_player_old;
    float Bot_tank_speed;
    int h=0;

    vector<SDL_Texture*> anim_shield;
    SDL_Texture* tex_load_shield;

    bool textt=true;

    int timebullet=400;
    int timereaction=-1;
    int timeangry;
    bool firs_react=false;
    bool firs_react_old=false;
    int x_size;
    int y_size;
    int x_tower_size=23*4;
    int y_tower_size=41*4;
    int anim_gus_stadi=0;
    int time_gus_anim=0;
    bool naprav=false;
    bool quit = false;
    double angle_turrel;
    double angle2;
    double angle3;

    double angle_move;

    SDL_Surface* image;
    SDL_Texture* texture;
    SDL_Texture* texture_pokoy;
    SDL_Texture* texture_acctive;
    SDL_Texture* texture_angry;
};

#endif // BOT_TANK_H_INCLUDED
