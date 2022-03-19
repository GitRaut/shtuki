#include "Bot_tank.h"
#include "GAME.h"
SDL_Texture* texture_bullet_tank;
SDL_Texture* texture_bashny;
SDL_Texture* texture_tank;


vector<SDL_Texture*> anim_red_korpus;
vector<SDL_Texture*> anim_green_korpus;
vector<double>marshrut_x{1423,2619};
vector<double>marshrut_y(4797,4797);

SDL_Texture* red_bashny;
SDL_Texture* green_bashny;
Bot_tank::Bot_tank(int x, int y, int width, int height, int speed,int m){
    //x_pos = x;
    //y_pos = y;

    //player.get_xpos();
    //angle = (atan2(y2-y, x2-x)*180.0000)/3.1416;
    //angle2 = atan2(y2-y, x2-x);
    if(m==0)
    {
       x_pos=marshrut_x[0];
        y_pos=4797;
        angle_move=0;
    }
    if(m==1)
    {
        x_pos=1742;
        y_pos=1869;
        angle_move=90;
    }
    if(m==3)
    {
        x_pos=1580;
        y_pos=1379;
        angle_move=0;
    }
    if(m==4)
    {
        x_pos=3888;
        y_pos=6515;
        angle_move=0;
    }

    x_size = width;
    y_size = height;
    Bot_tank_speed=speed*0.5;
    //texture = tex;
    live = true;
    angle2=rand()%360;
    marshrut=m;
}

Bot_tank::Bot_tank(){
}

void Bot_tank::move_Bot_tank(SDL_Renderer* renderer)
{

    double x_move,y_move;
    if(textt==true)
    {
        texture_from_image(renderer, red_bashny, image, "Textures_tank\\turrel_r.png");
        texture_from_image(renderer, green_bashny, image, "Textures_tank\\turrel_g.png");

        texture_from_image(renderer, texture_tank, image, "Textures\\tank.png");

        texture_from_image(renderer, texture_bashny, image, "Textures\\bashny.png");
        texture_from_image(renderer, texture_bullet_tank, image, "Textures\\bot_bullet.png");

        texture_from_image(renderer, texture_tank, image, "Textures_tank\\0_r.png");
        anim_red_korpus.push_back(texture_tank);
        texture_from_image(renderer, texture_tank, image, "Textures_tank\\1_r.png");
        anim_red_korpus.push_back(texture_tank);
        texture_from_image(renderer, texture_tank, image, "Textures_tank\\2_r.png");
        anim_red_korpus.push_back(texture_tank);
        texture_from_image(renderer, texture_tank, image, "Textures_tank\\3_r.png");
        anim_red_korpus.push_back(texture_tank);

        texture_from_image(renderer, texture_tank, image, "Textures_tank\\0_g.png");
        anim_green_korpus.push_back(texture_tank);
        texture_from_image(renderer, texture_tank, image, "Textures_tank\\1_g.png");
        anim_green_korpus.push_back(texture_tank);
        texture_from_image(renderer, texture_tank, image, "Textures_tank\\2_g.png");
        anim_green_korpus.push_back(texture_tank);
        texture_from_image(renderer, texture_tank, image, "Textures_tank\\3_g.png");
        anim_green_korpus.push_back(texture_tank);
        ////////////////////
        texture_from_image(renderer, tex_load_shield, image, "Texture_big_shield\\0.png");
        anim_shield.push_back(tex_load_shield);
        texture_from_image(renderer, tex_load_shield, image, "Texture_big_shield\\1.png");
        anim_shield.push_back(tex_load_shield);
        texture_from_image(renderer, tex_load_shield, image, "Texture_big_shield\\2.png");
        anim_shield.push_back(tex_load_shield);
        texture_from_image(renderer, tex_load_shield, image, "Texture_big_shield\\3.png");
        anim_shield.push_back(tex_load_shield);
        texture_from_image(renderer, tex_load_shield, image, "Texture_big_shield\\4.png");
        anim_shield.push_back(tex_load_shield);
        texture_from_image(renderer, tex_load_shield, image, "Texture_big_shield\\5.png");
        anim_shield.push_back(tex_load_shield);
        texture_from_image(renderer, tex_load_shield, image, "Texture_big_shield\\6.png");
        anim_shield.push_back(tex_load_shield);
        texture_from_image(renderer, tex_load_shield, image, "Texture_big_shield\\7.png");
        anim_shield.push_back(tex_load_shield);
        texture_from_image(renderer, tex_load_shield, image, "Texture_big_shield\\8.png");
        anim_shield.push_back(tex_load_shield);
        texture_from_image(renderer, tex_load_shield, image, "Texture_big_shield\\9.png");
        anim_shield.push_back(tex_load_shield);
        texture_from_image(renderer, tex_load_shield, image, "Texture_big_shield\\10.png");
        anim_shield.push_back(tex_load_shield);
        textt=false;
    }

    if(null_com==false)
    {
    if(time_gus_anim>0){time_gus_anim--;}
    if(is_visible(x_pos,y_pos,player.get_xpos(),player.get_ypos())==true)
    {
        angle_turrel = (atan2(player.get_ypos()-y_pos, player.get_xpos()-x_pos)*180.0000)/3.1416;

        firs_react=true;
        texture_bashny=red_bashny;
        texture_tank=anim_red_korpus[anim_gus_stadi];

        if(timereaction==-1)
        {
            timereaction=100;
            //texture = texture_angry;
            texture_bashny=red_bashny;
            texture_tank=anim_red_korpus[anim_gus_stadi];
        }
        if (timebullet != 0) timebullet--;
        if (timereaction >0) timereaction--;
        if (timeangry >0) timeangry--;
        if(timereaction==0)
        {
           texture = texture_acctive;
            if(timebullet ==0)
            {
                timebullet = 80;
                texture_bashny=red_bashny;
                texture_tank=anim_red_korpus[anim_gus_stadi];
                bullets.push_back(Bullet(x_pos,y_pos,player.get_xpos(),player.get_ypos(),35,45,texture_bullet_tank,3,0));
                Mix_PlayChannel(1, laser, 0);
                //(x_tower_size /2 ), (y_tower_size/2+ y_tower_size/4)
                //mciSendString(TEXT("play Sounds\\laser.wav"), NULL, 0, NULL);
            }
        }
    }else
    {
        texture_bashny=green_bashny;
        angle_turrel=angle_move;
        texture_tank=anim_green_korpus[anim_gus_stadi];
        if(marshrut==0)
        {

            if(naprav==true)
            {
               x_pos=x_pos+Bot_tank_speed;
               if(time_gus_anim==0)
               {
                time_gus_anim=30;
                anim_gus_stadi++;
                 if(anim_gus_stadi==4)
                 {
                     anim_gus_stadi=0;
                 }
                 //i++;
               }
            }
           if(naprav==false)
           {
                   x_pos=x_pos-Bot_tank_speed;
               if(time_gus_anim==0)
               {
                time_gus_anim=30;
                anim_gus_stadi++;
                 if(anim_gus_stadi==4)
                 {
                     anim_gus_stadi=0;
                 }
                 //i++;
               }
           }
           if(x_pos<=marshrut_x[0])// && naprav==false)
           {
               naprav=true;
           }
           if(x_pos>=marshrut_x[1])// && naprav==true)
           {
               naprav=false;
           }

        }
        if(marshrut==1)
        {
            k_smesh=20;
            if(naprav==true)
            {
               y_pos=y_pos+Bot_tank_speed;
               if(time_gus_anim==0)
               {
                time_gus_anim=30;
                anim_gus_stadi++;
                 if(anim_gus_stadi==4)
                 {
                     anim_gus_stadi=0;
                 }
                 //i++;
               }
            }
           if(naprav==false)
           {
                   y_pos=y_pos-Bot_tank_speed;

               if(time_gus_anim==0)
               {
                time_gus_anim=30;
                anim_gus_stadi++;
                 if(anim_gus_stadi==4)
                 {
                     anim_gus_stadi=0;
                 }
                 //i++;
               }
           }
           if(y_pos<=1868)// && naprav==false)
           {
               naprav=true;
           }
           if(y_pos>=3838)// && naprav==true)
           {
               naprav=false;
           }

        }
        if(marshrut==3)
        {

            if(naprav==true)
            {
               x_pos=x_pos+Bot_tank_speed;
               if(time_gus_anim==0)
               {
                time_gus_anim=30;
                anim_gus_stadi++;
                 if(anim_gus_stadi==4)
                 {
                     anim_gus_stadi=0;
                 }
                 //i++;
               }
            }
           if(naprav==false)
           {
                   x_pos=x_pos-Bot_tank_speed;
               if(time_gus_anim==0)
               {
                time_gus_anim=30;
                anim_gus_stadi++;
                 if(anim_gus_stadi==4)
                 {
                     anim_gus_stadi=0;
                 }
                 //i++;
               }
           }
           if(x_pos<=1550)// && naprav==false)
           {
               naprav=true;
           }
           if(x_pos>=3282)// && naprav==true)
           {
               naprav=false;
           }

        }
        if(marshrut==4)
        {

            if(naprav==true)
            {
               x_pos=x_pos+Bot_tank_speed;
               if(time_gus_anim==0)
               {
                time_gus_anim=30;
                anim_gus_stadi++;
                 if(anim_gus_stadi==4)
                 {
                     anim_gus_stadi=0;
                 }
                 //i++;
               }
            }
           if(naprav==false)
           {
                x_pos=x_pos-Bot_tank_speed;
               if(time_gus_anim==0)
               {
                time_gus_anim=30;
                anim_gus_stadi++;
                 if(anim_gus_stadi==4)
                 {
                     anim_gus_stadi=0;
                 }
                 //i++;
               }
           }
           if(x_pos<=3857)// && naprav==false)
           {
               naprav=true;
           }
           if(x_pos>=6287)// && naprav==true)
           {
               naprav=false;
           }

        }


    }
     if(life_bar_bot<=0)
    {
        Mix_PlayChannel(-1, boom, 0);
        live=false;
        Vzryvs.push_back(Vzryv(x_pos,y_pos, 290, 290));
        Gun_items.push_back(Gun_item(x_pos,y_pos,96,96,texture_tank,-2));
        player.bot_kill++;
        //Gun_items.push_back(Gun_item(x_pos,y_pos,96,96,texture_Bot_robots,-1));
    }
    }
    else if(null_com==true && time_nul==0)
    {
        time_nul=30;
        g=rand()%2-1;
        if(g==0)
        {
            texture_tank=anim_red_korpus[anim_gus_stadi];
        }
        if(g==-1)
        {
            texture_tank=anim_green_korpus[anim_gus_stadi];
        }
        angle_turrel=rand()%90;
        //tex_load_shield=anim_shield[rand()%9];

    }
    if(time_nul>0)time_nul--;
    ////render body
    screen_x=convert_x_to_screen(x_pos);
    screen_y=convert_y_to_screen(y_pos);
    SDL_Rect dstrect = {screen_x-x_size/2, screen_y-y_size/2, x_size, y_size};
    SDL_Point rotPoint = {(x_size / 2), (y_size / 2)};
    SDL_RenderCopyEx(renderer, texture_tank, NULL, &dstrect, angle_move + 90 , &rotPoint, SDL_FLIP_HORIZONTAL);
    //finish render body
    SDL_Rect towerrect = {screen_x-x_tower_size/2-x_tower_size/4+k_smesh, screen_y-y_tower_size/2-y_tower_size/4-k_smesh, x_tower_size, y_tower_size};
    SDL_Point towerrotPoint = {(x_tower_size /2 ), (y_tower_size/2+ y_tower_size/4)};
    SDL_RenderCopyEx(renderer, texture_bashny, NULL, &towerrect, angle_turrel +90, &towerrotPoint, SDL_FLIP_HORIZONTAL);
    ////////////////shield
    if(time_shield_anim>0)time_shield_anim--;
    if(time_shield_anim==0 && shield==true)
     {
         time_shield_anim=30;
        h++;
         if(h==11)
         {
             h=0;
         }
         tex_load_shield=anim_shield[h];
         //i++;
     }
     if(shield==true)
     {
         //sound of shield;
         SDL_Rect shield_rect = {screen_x - 295/2, screen_y - 295/2, 295, 295};
         //SDL_Point rotPoint = {(offset_x), (offset_y)};

         SDL_RenderCopy(renderer, tex_load_shield, NULL, &shield_rect);
     }

}

void Bot_tank::get_size(int &width, int &height){width = x_size; height = y_size;}
void Bot_tank::set_size(int width, int height){x_size = width, y_size = height;}

void Bot_tank::get_position(int &x, int &y){x = x_pos; y = y_pos;}
void Bot_tank::set_position(int x, int y){x_pos = x; y_pos = y;}

void Bot_tank::set_image(SDL_Surface* img){image = img;}
void Bot_tank::set_texture(SDL_Texture* tex){texture = tex;}

int Bot_tank::get_xpos(){return x_pos;}
int Bot_tank::get_ypos(){return y_pos;}

int Bot_tank::get_width(){return x_size;}
int Bot_tank::get_height(){return y_size;}
