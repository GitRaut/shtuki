#include "GAME.h"
#include "Bot_robot.h"
#include "Bullet.h"
#include "Vzryv.h"
#include "Player.h"

//SDL_Texture* texture_vzryv;

Vzryv::Vzryv(int x, int y, int width, int height){
    x_pos = x;
    y_pos = y;
    x_size = width;
    y_size = height;
    //Bot_robot_speed=speed;
//    texture = tex;
    live = true;
    angle2=rand()%360;
    //texture_from_image(renderer, texture_bullet_bot, image_bullet_bot, "bot_bullet.png");
}
void Vzryv::update_vzryv(SDL_Renderer* renderer)
{
    if(textt==true)
    {
        //texture_from_image(renderer, texture_vzryv, image, "pngwing.com.png");
        textt=false;
    }
    if(time>0)time--;
    //kadr_sum++;
    if(kadr_sum==44)live=false;

    if(kadr>8) {kadr_xpos=0;kadr_ypos=kadr_ypos+240;kadr=0;}

    if(time==0)
    {
        kadr_xpos=kadr_xpos+240;
        kadr_sum++;
        kadr++;
        time=5;
    }
    SDL_Rect srcrect = {kadr_xpos, kadr_ypos, 240, 240};

        screen_x=convert_x_to_screen(x_pos);
        screen_y=convert_y_to_screen(y_pos);

        SDL_Rect dstrect = {screen_x-x_size/2, screen_y-y_size/2, x_size, y_size};
        SDL_Point rotPoint = {(x_size / 2), (y_size / 2)};
    //SDL_Rect dstrect = {x_pos-x_size/2, y_pos-y_size/2, x_size, y_size};
    //SDL_Point rotPoint = {(x_size / 2), (y_size / 2)};


    //SDL_RenderCopyEx(renderer, texture_vzryv, &srcrect, &dstrect, angle + 90 , &rotPoint, SDL_FLIP_HORIZONTAL);
    SDL_RenderCopyEx(renderer, texture_vzryv, &srcrect, &dstrect, 0 , NULL, SDL_FLIP_HORIZONTAL);

}

void Vzryv::get_size(int &width, int &height){width = x_size; height = y_size;}
void Vzryv::set_size(int width, int height){x_size = width, y_size = height;}

void Vzryv::get_position(int &x, int &y){x = x_pos; y = y_pos;}
void Vzryv::set_position(int x, int y){x_pos = x; y_pos = y;}

void Vzryv::set_image(SDL_Surface* img){image = img;}
void Vzryv::set_texture(SDL_Texture* tex){texture = tex;}

int Vzryv::get_xpos(){return x_pos;}
int Vzryv::get_ypos(){return y_pos;}

int Vzryv::get_width(){return x_size;}
int Vzryv::get_height(){return y_size;}
