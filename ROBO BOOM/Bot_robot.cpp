#include "GAME.h"


SDL_Texture* texture_bullet_bot;
SDL_Surface* image_bullet_bot;

Bot_robot::Bot_robot(int x, int y, int width, int height, SDL_Texture* tex, int speed){
    x_pos = x;
    y_pos = y;
    //k = (float)(y2 - y)/(float)(x2 - x);

    //x2_pos = (x2>x)?1:-1;
    //y2_pos = (y2>y)?-1:1;
    //player.get_xpos();
    //angle = (atan2(y2-y, x2-x)*180.0000)/3.1416;
    //angle2 = atan2(y2-y, x2-x);

    x_size = width;
    y_size = height;
    Bot_robot_speed=speed;
    texture = tex;
    live = true;
    angle2=rand()%360;
    //texture_from_image(renderer, texture_bullet_bot, image_bullet_bot, "bot_bullet.png");
}
void Bot_robot::move_Bot_robot(SDL_Renderer* renderer)
{

    //angle = (angle2*180.0000)/3.1416;
    //angle = (atan2(player.get_ypos()-y_pos, player.get_xpos()-x_pos)*180.0000)/3.1416;
    //angle3 = (atan2(y2_pos_player_old-y_pos, x2_pos_player_old-x_pos);

    //angle2 = atan2(y2_pos-y_pos, x2_pos-x_pos);
    if(null_com==false)
    {

    double x_move,y_move;
    if(textt==true)
    {
        texture_from_image(renderer, texture_bullet_bot, image_bullet_bot, "Textures\\bot_bullet.png");
        texture_from_image(renderer, texture_pokoy, image, "Textures\\bot.png");
        texture_from_image(renderer, texture_acctive, image, "Textures\\bot_active.png");
        texture_from_image(renderer, texture_angry, image, "Textures\\bot_angry.png");
        textt=false;
    }
    if (timebullet != 0) timebullet--;
    if (timereaction >0) timereaction--;
    if (timeangry >0) timeangry--;
    if(is_visible(x_pos,y_pos,player.get_xpos(),player.get_ypos())==true)
    {
        angle = (atan2(player.get_ypos()-y_pos, player.get_xpos()-x_pos)*180.0000)/3.1416;
        firs_react=true;

        if(timereaction==-1){timereaction=100;texture = texture_angry;}
        if(timereaction==0)
        {
           texture = texture_acctive;
            if(timebullet ==0)
            {
                timebullet = 80;
                bullets.push_back(Bullet(x_pos,y_pos,player.get_xpos(),player.get_ypos(),30,40,texture_bullet_bot,3,0));
                Mix_PlayChannel(1, laser, 0);
            }
        }
        //angle2 = atan2(player.get_ypos()-y_pos, player.get_xpos()-x_pos);
        x_move = x_pos + Bot_robot_speed*cos(angle)/8;
        y_move = y_pos + Bot_robot_speed*sin(angle)/8;

        //firs_react_old=firs_react;

    }else
    {
        //angle=rand()%180;

        if(firs_react==true)
        {
            y2_pos_player_old=player.get_ypos();
            x2_pos_player_old=player.get_xpos();
            angle3 = (atan2(y2_pos_player_old-y_pos, x2_pos_player_old-x_pos));
            firs_react=false;
            timeangry=600;
        }
        if(timeangry>0)
        {
            texture = texture_acctive;
            x_move = x_pos + Bot_robot_speed*cos(angle3)/2;
            y_move = y_pos + Bot_robot_speed*sin(angle3)/2;

        }
        else if(timeangry==0)
        {
            texture = texture_pokoy;
           x_move = x_pos + Bot_robot_speed*cos(angle2)/4;
           y_move = y_pos + Bot_robot_speed*sin(angle2)/4;

        }
        texture = texture_pokoy;
        timereaction=-1;


    }
    //x_pos = x_pos + Bot_robot_speed*cos(angle2)/2;
    //y_pos = y_pos + Bot_robot_speed*sin(angle2)/2;
    if(life_bar_bot<=0)
    {
        Mix_PlayChannel(-1, boom, 0);
        live=false;
        Vzryvs.push_back(Vzryv(x_pos,y_pos, 150, 150));
        Gun_items.push_back(Gun_item(x_pos,y_pos,96,96,texture_Bot_robots,-1));
        player.bot_kill++;
    }

    if (is_collision_pl(x_move,y_move,x_size-10,y_size-10)==true)
    {
        angle2=rand()%360;
        int new_x,new_y;
        new_x = x_pos + tile_size*cos(angle2);
        new_y = y_pos + tile_size*sin(angle2);
        int num=100;
        while(is_collision_pl(new_x,new_y,x_size-10,y_size-10)==true)
        {
            num--;
            if (num==0) break;
            angle2=rand()%360;
            new_x = x_pos + tile_size*cos(angle2);
            new_y = y_pos + tile_size*sin(angle2);
        }
    } else {
        x_pos=x_move;
        y_pos=y_move;

    }
    }else if(null_com==true)
    {
        angle=rand()%360;
    }
    if(shield_prochnost==0)
    {
        shield=false;
    }


    screen_x=convert_x_to_screen(x_pos);
    screen_y=convert_y_to_screen(y_pos);

        SDL_Rect dstrect = {screen_x-x_size/2, screen_y-y_size/2, x_size, y_size};
        SDL_Point rotPoint = {(x_size / 2), (y_size / 2)};


    SDL_RenderCopyEx(renderer, texture, NULL, &dstrect, angle - 90 , &rotPoint, SDL_FLIP_HORIZONTAL);




}

void Bot_robot::get_size(int &width, int &height){width = x_size; height = y_size;}
void Bot_robot::set_size(int width, int height){x_size = width, y_size = height;}

void Bot_robot::get_position(int &x, int &y){x = x_pos; y = y_pos;}
void Bot_robot::set_position(int x, int y){x_pos = x; y_pos = y;}

void Bot_robot::set_image(SDL_Surface* img){image = img;}
void Bot_robot::set_texture(SDL_Texture* tex){texture = tex;}

int Bot_robot::get_xpos(){return x_pos;}
int Bot_robot::get_ypos(){return y_pos;}

int Bot_robot::get_width(){return x_size;}
int Bot_robot::get_height(){return y_size;}
