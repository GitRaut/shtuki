#include "GAME.h"
#include "Player.h"

SDL_Texture* texture_null_ocrush;
SDL_Texture* live_bar_el_shield;
extern vector<Bot_tank> Bot_tanks;

Player::Player(){};
Player::Player(SDL_Texture* tex, int x, int y, int w, int h){
    texture = tex;
    x_pos = x;
    y_pos = y;
    x_size = w;
    y_size = h;
    offset_x = x_size / 2;
    offset_y = y_size / 2;
    scr_x = win_w / 2;
    scr_y = win_h / 2;
}
int Player::get_gun_type()
{
    return gun_type_player;
}
void Player::set_gun_type(int type)
{
    gun_type_player=type;
}
void Player::update(SDL_Renderer* renderer){
    if(texxt==true)
    {
        texxt=false;
        texture_from_image(renderer, texture_null_ocrush, image, "Textures\\okrush_moln.png");
        texture_from_image(renderer, live_bar_el_shield, image, "Textures\\life_bar_el_2.png");

        texture_from_image(renderer, tex_load_shield, image, "Texture_shield\\0.png");
        anim_shield.push_back(tex_load_shield);
        texture_from_image(renderer, tex_load_shield, image, "Texture_shield\\1.png");
        anim_shield.push_back(tex_load_shield);
        texture_from_image(renderer, tex_load_shield, image, "Texture_shield\\2.png");
        anim_shield.push_back(tex_load_shield);
        texture_from_image(renderer, tex_load_shield, image, "Texture_shield\\3.png");
        anim_shield.push_back(tex_load_shield);
        texture_from_image(renderer, tex_load_shield, image, "Texture_shield\\4.png");
        anim_shield.push_back(tex_load_shield);
        texture_from_image(renderer, tex_load_shield, image, "Texture_shield\\5.png");
        anim_shield.push_back(tex_load_shield);
        texture_from_image(renderer, tex_load_shield, image, "Texture_shield\\6.png");
        anim_shield.push_back(tex_load_shield);
        texture_from_image(renderer, tex_load_shield, image, "Texture_shield\\7.png");
        anim_shield.push_back(tex_load_shield);
        texture_from_image(renderer, tex_load_shield, image, "Texture_shield\\8.png");
        anim_shield.push_back(tex_load_shield);
    }
    SDL_GetMouseState(&x_mouse,&y_mouse);
    if (GetAsyncKeyState('W')){
        y_pos -= 1;
        if(gun_type_player==2){timeactive==200;}
        if(is_collision_pl(x_pos, y_pos,x_size,y_size)){
                y_pos += 1;
        }
    }
    if (GetAsyncKeyState('S')){
        y_pos += 1;
        if(gun_type_player==2){timeactive==200;}
        if(is_collision_pl(x_pos, y_pos,x_size,y_size)){
            y_pos -= 1;
        }
    }
    if (GetAsyncKeyState('A')){
        x_pos -= 1;
        if(gun_type_player==2){timeactive==200;}
        if(is_collision_pl(x_pos, y_pos,x_size,y_size)){
            x_pos += 1;
        }
    }
    if (GetAsyncKeyState('D')){
        x_pos += 1;
        if(gun_type_player==2){timeactive==200;}
        if(is_collision_pl(x_pos, y_pos,x_size,y_size)){
            x_pos -= 1;
        }
    }
    if(GetAsyncKeyState(VK_LBUTTON)){l = true;}else{l = false;}
    if (GetAsyncKeyState('R'))
    {
        if(kool_down_null_comm == 0)
        {
           Mix_PlayChannel(-1, skill, 0);
           bot_null_com=true;
           smesh=10;
           kool_down_null_comm =5000;
        }
    }
    else{
        bot_null_com = false;
    }
    if (GetAsyncKeyState('E'))
    {
        p=true;
    }else
    {
        p=false;
    }
    /////стрельба
    //cout<<kool_down_null_comm;
    if (timebullet != 0) timebullet--;
    if (kool_down_null_comm > 0) kool_down_null_comm--;
        if (timeactive > 0) timeactive--;
        if( l==true && timebullet ==0 && Kol_patronov>0)
        {
            if(get_gun_type()==1){
                bullets.push_back(Bullet(x_pos,y_pos,x_mouse + (player.x_pos - (win_w / 2)),y_mouse + (player.y_pos - (win_h / 2)),12,15,pistol_bullet,4,1));
                timebullet = 180;
                Mix_PlayChannel(3, pistolet, 0);
            }
            if(get_gun_type()==2){
                bullets.push_back(Bullet(x_pos,y_pos,x_mouse + (player.x_pos - (win_w / 2)),y_mouse + (player.y_pos - (win_h / 2)),13,23,automat_bullet,4,2));
                timebullet = 50;
                Mix_VolumeChunk(avtomat, ef_loud - 16);
                Mix_PlayChannel(3, avtomat, 0);
            }
            if(get_gun_type()==3){
                    bullets.push_back(Bullet(x_pos,y_pos,x_mouse + (player.x_pos - (win_w / 2)), y_mouse + (player.y_pos - (win_h / 2)),40,60,rpg_bullet,1,3));
                    timebullet = 400;
                    Mix_VolumeChunk(rpg, ef_loud - 16);
                    Mix_PlayChannel(3, rpg, 0);
            }
            Kol_patronov--;
            l=false;
            //bullets.push_back(Bullet(x_pos,y_pos,x_mouse,y_mouse,10,10,texture_bullet,1));
            //Bullet pulka = Bullet(x_pos,y_pos,x_mouse,y_mouse,30,30,texture,10);
            //pulka.move_bullet;
        }
        else if(l == true && timebullet == 0 && Kol_patronov == 0){
            Mix_PlayChannel(2, null, 0);
        }
     /////стрельба конец

     //null_com
     if(bot_null_com==true)
     {
         time_null_com=200;
         bot_null_com==false;
     }
     if(shield_prochnost<=0)
     {
         shield=false;
     }
     if(time_shield_anim>0)time_shield_anim--;
     if(time_null_com>0)time_null_com--;
     if(time_bot_null_com>0)time_bot_null_com--;

     if(time_null_com>0 && time_null_com!=-1)
     {
         smesh+=30;
         SDL_Rect moln_rec = {convert_x_to_screen(x_pos)-smesh+(x_size+smesh)/2,convert_y_to_screen(y_pos)-smesh+(y_size+smesh)/2, 10+smesh, 10+smesh};
        //SDL_Point moln_rotPoint = {(offset_x), (offset_y)};

        SDL_RenderCopy(renderer, texture_null_ocrush, NULL, &moln_rec);
        for (int i=Bot_robots.size()-1;i>=0;i--){
            Bot_robots[i].null_com=true;
        }
        for (int i=Bot_tanks.size()-1;i>=0;i--){
            Bot_tanks[i].null_com=true;
        }
        time_bot_null_com=1000;

     }else
     {
       for (int i=Bot_robots.size()-1;i>=0;i--){
            Bot_robots[i].null_com=false;
        }
        for (int i=Bot_tanks.size()-1;i>=0;i--){
            Bot_tanks[i].null_com=false;
        }
     }
     if(time_bot_null_com>0 && time_bot_null_com!=-1)
     {
         for (int i=Bot_robots.size()-1;i>=0;i--){
            Bot_robots[i].null_com=true;
        }
        for (int i=Bot_tanks.size()-1;i>=0;i--){
            Bot_tanks[i].null_com=true;
        }
     }
     else
     {
        for (int i=Bot_robots.size()-1;i>=0;i--){
            Bot_robots[i].null_com=false;
        }
        time_bot_null_com=-1;
     }
     //if(time_null_com==0)
     //{
         //for (int i=Bot_robots.size()-1;i>=0;i--){
            //Bot_robots[i].null_com=true;
        //}
     //}

     //null_com
    delta_x = scr_x - x_mouse;
    delta_y = scr_y - y_mouse;
    angle = (atan2(delta_y, delta_x)*180.0000)/3.1416;

    SDL_Rect player_rect = {scr_x - offset_x, scr_y - offset_y, x_size, y_size};
    SDL_Point rotPoint = {(offset_x), (offset_y)};

    SDL_RenderCopyEx(renderer, texture, NULL, &player_rect, angle + 90, &rotPoint, SDL_FLIP_HORIZONTAL);

     if(time_shield_anim==0 && shield==true)
     {
         time_shield_anim=30;
        h++;
         if(h==9)
         {
             h=0;
         }
         tex_load_shield=anim_shield[h];
         //i++;
     }
     if(shield==true)
     {
         SDL_Rect shield_rect = {scr_x - 130/2, scr_y - 130/2, 130, 130};
         //SDL_Point rotPoint = {(offset_x), (offset_y)};

         SDL_RenderCopy(renderer, tex_load_shield, NULL, &shield_rect);
         int smesh=0;

        for(int i=0;i<shield_prochnost/4;i++)
        {   smesh+=9;
             SDL_Rect shield_pr_el_rect = {convert_x_to_screen(x_pos)+smesh-150,convert_y_to_screen(y_pos)+smesh-5, 11*2, 8*2};
             SDL_Point rotPoint_elic = {((80*5) / 3), ( (22*3) / 2)};

            SDL_RenderCopyEx(renderer, live_bar_el_shield, NULL, &shield_pr_el_rect, 90, &rotPoint_elic, SDL_FLIP_NONE);
        }
     }
     //cout<<x_pos<<y_pos<<endl;
}
void Player::set_texture(SDL_Texture* tex){texture = tex;}

int Player::get_xpos(){return x_pos;}
int Player::get_ypos(){return y_pos;}//14234797 26194756
//int Player::get_x_mouse(){return x_mouse;}
//int Player::get_y_mouse(){return y_mouse;}
