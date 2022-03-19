#ifndef VZRYV_H_INCLUDED
#define VZRYV_H_INCLUDED

#include "GAME.h"
#include "Bot_robot.h"
#include "Bullet.h"

class Vzryv{
public:
    Vzryv(int x, int y, int width, int height);
    ~Vzryv(){}

    void update_vzryv(SDL_Renderer* renderer);



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
    float k;
    int x_smesheniye;
    double x_pos;
    double y_pos;
    double kadr_xpos=0;
    double kadr_ypos=0;
    double x2_pos_player_old;
    double y2_pos_player_old;
    float Bot_robot_speed;

    bool textt=true;

    int screen_x;
    int screen_y;

    int time=10;
    int kadr=0;
    int kadr_sum=0;
    bool firs_react=false;
    bool firs_react_old=false;
    int x_size;
    int y_size;
    bool quit = false;
    double angle;
    double angle2;
    double angle3;
    SDL_Surface* image;
    SDL_Texture* texture;

};

#endif // VZRYV_H_INCLUDED
