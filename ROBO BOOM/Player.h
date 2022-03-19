#pragma once
#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include "GAME.h"

class Player{
public:
    Mix_Chunk* avtomat = Mix_LoadWAV("Sounds\\ak_47.wav");
    Mix_Chunk* pistolet = Mix_LoadWAV("Sounds\\pistolet.wav");
    Mix_Chunk* rpg = Mix_LoadWAV("Sounds\\rpg.wav");
    Mix_Chunk* null = Mix_LoadWAV("Sounds\\null_patron.wav");
    Mix_Chunk* take = Mix_LoadWAV("Sounds\\take.wav");
    Mix_Chunk* skill = Mix_LoadWAV("Sounds\\skill_sound.wav");
    Player(SDL_Texture* tex, int x, int y, int w, int h);
    Player();

    double x_pos, y_pos;
    int speed;
    int x_mouse, y_mouse;
    SDL_Texture* texture;
    void set_texture(SDL_Texture* tex);

    int get_xpos();
    int get_ypos();

    void set_gun_type(int type);
    int get_gun_type();
    int lives_bar=100;
    int Kol_patronov=0;
    //int get_x_mouse()
    //int get_y_mouse()
    bool shield=false;
    int bot_kill=0;
    int shield_prochnost=25;
    bool bot_null_com=false;
    int kool_down_null_comm=0;
    int time_null_com=-1;
    int time_shield_anim=0;

    void update(SDL_Renderer* renderer);

private:
    vector<SDL_Texture*> anim_shield;
    SDL_Texture* tex_load_shield;
    bool texxt=true;
    int h=0;
    int gun_type_player=0;
    int timebullet=200;
    int timeactive;
    int time_bot_null_com=-1;
    double angle;
    int delta_x, delta_y;
    double offset_x, offset_y;
    int scr_x, scr_y;
    int x_size, y_size;
    int smesh=10;
    SDL_Surface* image;
};

#endif // PLAYER_H_INCLUDED
