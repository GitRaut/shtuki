#include "GAME.h"
#include "Bullet.h"
#include "Vzryv.h"
#include "Player.h"

extern Prisoner prisoner;
extern vector<Bot_tank> Bot_tanks;

Bullet::Bullet(int x, int y,int x2,int y2, int width, int height, SDL_Texture* tex, int speed,int type){
    x_pos = x;
    y_pos = y;
    k = (float)(y2 - y)/(float)(x2 - x);

    x2_pos =x2;// (x2>x)?1:-1;
    y2_pos =y2;// (y2>y)?-1:1;

    angle = (atan2(y2-y, x2-x)*180.0000)/3.1416;
    angle2 = atan2(y2-y, x2-x);
    type_bullet=type;
    x_size = width;
    y_size = height;
    bullet_speed=speed;
    texture = tex;
    live = true;
}
void Bullet::move_bullet(SDL_Renderer* renderer)
{
    //int y=(int)k*x_smesheniye;
    //SDL_RenderDrawPoint(renderer,x_smesheniye,y);
    //x_smesheniye=x_smesheniye+bullet_speed;

    //x_pos = x_pos + bullet_speed * x2_pos;

    x_pos = x_pos + bullet_speed*cos(angle2);
    y_pos = y_pos + bullet_speed*sin(angle2);

    //y_pos = y_pos + bullet_speed * k * x2_pos;
    //if( && x_pos==x2_pos && y_pos==y2_pos){live=false;}
    if(((player.get_xpos()<x_pos+50 && player.get_ypos()<y_pos+50)&& (player.get_xpos()>x_pos-50 && player.get_ypos()>y_pos-50) ) && type_bullet==0 )
    {
        if(player.shield==false)
        {
           live = false;
           if(type_bullet==3) {
                Vzryvs.push_back(Vzryv(x_pos,y_pos, 150, 150));
                Mix_PlayChannel(-1, boom, 0);
           }
           player.lives_bar-=15;/////////////////////////////////////'yron
        }else
        {
            Mix_PlayChannel(-1, recos, 0);
            angle2=180-rand()%160;
            angle = (angle2*180.0000)/3.1416;
            player.shield_prochnost--;
            x_pos = x_pos + 50*cos(angle2);
            y_pos = y_pos + 50*sin(angle2);

        }

    }
    for (int i=Bot_robots.size()-1;i>=0;i--){
            if (((Bot_robots[i].get_xpos()<x_pos+50 && Bot_robots[i].get_ypos()<y_pos+50)&& (Bot_robots[i].get_xpos()>x_pos-50 && Bot_robots[i].get_ypos()>y_pos-50) ) && (type_bullet==1 || type_bullet==2 || type_bullet==3) ) {
                if(Bot_robots[i].null_com==false)
                {
                   Bot_robots[i].life_bar_bot-=20;
                    if(type_bullet==1)Bot_robots[i].life_bar_bot-=50;
                    if(type_bullet==2)Bot_robots[i].life_bar_bot-=30;
                    if(type_bullet==3)Bot_robots[i].life_bar_bot-=1000;
                }

                    live = false;
                //}

                //if(type_bullet==3) Vzryvs.push_back(Vzryv(x_pos,y_pos, 150, 150));
            }
        }
    for (int i=Bot_tanks.size()-1;i>=0;i--){
            if (((Bot_tanks[i].get_xpos()<x_pos+120 && Bot_tanks[i].get_ypos()<y_pos+120)&& (Bot_tanks[i].get_xpos()>x_pos-120 && Bot_tanks[i].get_ypos()>y_pos-120) ) && (type_bullet==1 || type_bullet==2 || type_bullet==3) ) {
                //Bot_tanks[i].shield==false;
                if(Bot_tanks[i].shield==true)
                {
                    //Bot_tanks[i].shield==false;
                    if(type_bullet==3)
                    {
                        Bot_tanks[i].shield=false;
                        live=false;
                        //Bot_robots[i].shield==false;
                    }else
                    {
                        //sound of recoshet
                       angle2=180-rand()%160;
                        angle = (angle2*180.0000)/3.1416;
                    }

                    //Bot_robots[i].shield_prochnost--;

                }else
                {
                    if(type_bullet==3 && Bot_tanks[i].null_com==false)
                    {
                        Bot_tanks[i].life_bar_bot-=600;
                    }else
                    {
                        if( Bot_tanks[i].null_com==false)
                            Bot_tanks[i].life_bar_bot-=20;
                    }

                    live = false;
                }

                //if(type_bullet==3) Vzryvs.push_back(Vzryv(x_pos,y_pos, 250, 250));
            }
        }
    if(((prisoner.x_pos<x_pos+50 && prisoner.y_pos<y_pos+50)&& (prisoner.x_pos>x_pos-50 && prisoner.y_pos>y_pos-50) ) && type_bullet==0 && prisoner.svoboda==true)
    {
        live = false;
        prisoner.hp_prisoner-=20;
    }

    if (is_collision(x_pos,y_pos)==true)
    {
        live = false;
        if(type_bullet==3){
            Vzryvs.push_back(Vzryv(x_pos,y_pos, 150, 150));
            Mix_PlayChannel(-1, boom, 0);
        }
        return;
    }
        screen_x=convert_x_to_screen(x_pos);
        screen_y=convert_y_to_screen(y_pos);

        SDL_Rect dstrect = {screen_x-x_size/2, screen_y-y_size/2, x_size, y_size};
        SDL_Point rotPoint = {(x_size / 2), (y_size / 2)};

        //SDL_Rect dstrect = {x_pos, y_pos, x_size, y_size};
        //SDL_Point rotPoint = {(x_size / 2), (y_size / 2)};


    SDL_RenderCopyEx(renderer, texture, NULL, &dstrect, angle + 90 , &rotPoint, SDL_FLIP_HORIZONTAL);




}

void Bullet::get_size(int &width, int &height){width = x_size; height = y_size;}
void Bullet::set_size(int width, int height){x_size = width, y_size = height;}

void Bullet::get_position(int &x, int &y){x = x_pos; y = y_pos;}
void Bullet::set_position(int x, int y){x_pos = x; y_pos = y;}

void Bullet::set_image(SDL_Surface* img){image = img;}
void Bullet::set_texture(SDL_Texture* tex){texture = tex;}

int Bullet::get_xpos(){return x_pos;}
int Bullet::get_ypos(){return y_pos;}

int Bullet::get_width(){return x_size;}
int Bullet::get_height(){return y_size;}
