#ifndef GUN_H_INCLUDED
#define GUN_H_INCLUDED

#include "GAME.h"
#include "Bot_robot.h"
#include "Bullet.h"

class Gun_item{
public:
    Gun_item(int x, int y, int width, int height, SDL_Texture* tex,int type);
    ~Gun_item(){}

    void pick_up_gun(SDL_Renderer* renderer, bool pick);



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
    Mix_Chunk* shield_active = Mix_LoadWAV("Sounds\\shield_sound.wav");
    float k;
    int x_smesheniye;
    double x_pos;
    double y_pos;
    double x2_pos;
    double y2_pos;
    double x2_pos_player_old;
    double y2_pos_player_old;
    float Bot_robot_speed;

    bool textt=true;

    int time_pick=100;
    int type_gun;
    bool firs_react=false;
    bool firs_react_old=false;
    int x_size;
    int y_size;
    bool quit = false;
    double angle;
    double angle2;
    double angle3;
    int screen_x;
    int screen_y;
    SDL_Surface* image;
    SDL_Texture* texture;

};

#endif // GUN_H_INCLUDED
