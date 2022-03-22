#include "GAME.h"
#include "Bot_robot.h"
#include "Bullet.h"
#include "Gun.h"
#include "Player.h"

SDL_Texture* texture_pistol;
    SDL_Texture* texture_automat;
    SDL_Texture* texture_rpg;

    SDL_Texture* pistol;
    SDL_Texture* automat;
    SDL_Texture* rpg;

    SDL_Texture* dead_bot;
    SDL_Texture* dead_tank;
    SDL_Texture* first_aid_kit;
    SDL_Texture* pl_shield;
extern Prisoner prisoner;

Gun_item::Gun_item(int x,int y, int width, int height, SDL_Texture* tex, int type){
    x_pos = x;
    y_pos = y;
    x_size = width;
    y_size = height;
    texture = tex;
    live = true;
    type_gun=type;
    angle=rand()%360;

    //texture_from_image(renderer, texture_bullet_bot, image_bullet_bot, "bot_bullet.png");
}
//type=1--pistol
//type=2--avtomat
//type=3--rpg
//type=4--first aid
//type=5--bot_null_com
void Gun_item::pick_up_gun(SDL_Renderer* renderer, bool pick)
{
    if(textt==true)
    {
        texture_from_image(renderer, pl_shield, image, "Texture_shield\\8.png");
        texture_from_image(renderer, first_aid_kit, image, "Textures\\old_heal.png");
        texture_from_image(renderer, texture_pistol, image, "Textures\\player_pistolet.png");
        texture_from_image(renderer, texture_automat, image, "Textures\\player_avtomat_active.png");
        texture_from_image(renderer, texture_rpg, image, "Textures\\player_rpg.png");
        texture_from_image(renderer, dead_bot, image, "Textures\\NEGR_BOT.png");
        texture_from_image(renderer, dead_tank, image, "Textures\\negr_tank.png");

        texture_from_image(renderer, pistol, image, "Textures\\pistol_text.png");
        texture_from_image(renderer, automat, image, "Textures\\Automat_text.png");
        texture_from_image(renderer, rpg, image, "Textures\\rpg_text.png");
        textt=false;

    }
    if(type_gun==-2){texture=dead_tank;x_size=33*3; y_size=39*3;}
    if(type_gun==-1){texture=dead_bot;x_size=96; y_size=86;}
    if(type_gun==1){texture=pistol;x_size=46; y_size=46;}
    if(type_gun==2){texture=automat;x_size=250/3; y_size=125/3;}
    if(type_gun==3){texture=rpg;x_size=12*3, y_size=37*3;}
    if(type_gun==4){texture=first_aid_kit;x_size=56, y_size=56;}
    if(type_gun==5){texture=pl_shield;x_size=30*2, y_size=30*2;}
    if(time_pick>0) time_pick--;
    //texture=automat;
    if ( ((player.get_xpos()<x_pos+50 && player.get_ypos()<y_pos+50)&& (player.get_xpos()>x_pos-50 && player.get_ypos()>y_pos-50) ) && pick==true && time_pick==0)
    {
        if(type_gun==1)
        {   player.set_texture(texture_pistol);
            if(player.get_gun_type()==1){type_gun=1;}
            if(player.get_gun_type()==2){type_gun=2;}
            if(player.get_gun_type()==3){type_gun=3;}
            if(player.get_gun_type()==0){live=false;}
            if(player.get_gun_type()==4){player.lives_bar=100;live=false;}
            player.set_gun_type(1);
            Mix_PlayChannel(3, player.take, 0);
            player.Kol_patronov=10;
            //live=false;
        }else if(type_gun==2)
        { player.set_texture(texture_automat);
            if(player.get_gun_type()==1){type_gun=1;}
            if(player.get_gun_type()==2){type_gun=2;}
            if(player.get_gun_type()==3){type_gun=3;}
            if(player.get_gun_type()==0){live=false;}
            if(player.get_gun_type()==4){player.lives_bar=100;live=false;}
            player.set_gun_type(2);
            Mix_PlayChannel(3, player.take, 0);
            player.Kol_patronov=30;
            //live=false;
        } else if(type_gun==3)
        {   player.set_texture(texture_rpg);
            if(player.get_gun_type()==1){type_gun=1;}
            if(player.get_gun_type()==2){type_gun=2;}
            if(player.get_gun_type()==3){type_gun=3;}
            if(player.get_gun_type()==0){live=false;}
            if(player.get_gun_type()==4){player.lives_bar=100;live=false;}
            player.set_gun_type(3);
            Mix_PlayChannel(3, player.take, 0);
            player.Kol_patronov=3;
            //live=false;
        }else if(type_gun==4)
        {
            player.lives_bar=100;live=false;
        }else if(type_gun==5)
        {
            Mix_PlayChannel(-1, shield_active, 0);
            player.shield=true;
            player.shield_prochnost=20;
            live=false;
        }
        time_pick=300;
    }
    if ( ((prisoner.get_xpos()<x_pos+50 && prisoner.get_ypos()<y_pos+50)&& (prisoner.get_xpos()>x_pos-50 && prisoner.get_ypos()>y_pos-50) ) && type_gun==4 &&prisoner.hp_prisoner<50)
    {
        live=false;
        prisoner.hp_prisoner=50;
    }

    screen_x=convert_x_to_screen(x_pos);
    screen_y=convert_y_to_screen(y_pos);

    SDL_Rect dstrect = {screen_x-x_size/2, screen_y-y_size/2, x_size, y_size};
    SDL_Point rotPoint = {(x_size / 2), (y_size / 2)};

    SDL_RenderCopyEx(renderer, texture, NULL, &dstrect, angle, &rotPoint, SDL_FLIP_HORIZONTAL);




}

void Gun_item::get_size(int &width, int &height){width = x_size; height = y_size;}
void Gun_item::set_size(int width, int height){x_size = width, y_size = height;}

void Gun_item::get_position(int &x, int &y){x = x_pos; y = y_pos;}
void Gun_item::set_position(int x, int y){x_pos = x; y_pos = y;}

void Gun_item::set_image(SDL_Surface* img){image = img;}
void Gun_item::set_texture(SDL_Texture* tex){texture = tex;}

int Gun_item::get_xpos(){return x_pos;}
int Gun_item::get_ypos(){return y_pos;}

int Gun_item::get_width(){return x_size;}
int Gun_item::get_height(){return y_size;}
