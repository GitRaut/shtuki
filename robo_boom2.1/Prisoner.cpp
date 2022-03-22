#include "Prisoner.h"
#include "GAME.h"
SDL_Texture* texture_zalosh_passive;
SDL_Texture* texture_zalosh_active;
SDL_Texture* texture_zalosh_dead;
SDL_Texture* texture_zalosh;
SDL_Texture* live_bar_el_prison;

Prisoner::Prisoner(int x, int y, int w, int h){
    x_pos = x;
    y_pos = y;
    x_size = w;
    y_size = h;
    offset_x = x_size / 2;
    offset_y = y_size / 2;
    scr_x = win_w / 2;
    scr_y = win_h / 2;
}

Prisoner::Prisoner(){
}

void Prisoner::update(SDL_Renderer* renderer)
{
    if(textt==true)
    {
        texture_from_image(renderer, texture_zalosh_passive, image, "Textures\\prisoner.png");
        texture_from_image(renderer, live_bar_el_prison, image, "Textures\\life_el_prisoner.png");
        texture_from_image(renderer, texture_zalosh_dead, image, "Textures\\dead_prisoner.png");
        texture_from_image(renderer, texture_zalosh_active, image, "Textures\\prisoner_free.png");
        textt=false;
    }
    int smesh=0;

    for(int i=0;i<hp_prisoner/20;i++)
    {   smesh+=9;
         SDL_Rect live_bar_el_prisoner_rect = {convert_x_to_screen(x_pos)+smesh-150,convert_y_to_screen(y_pos)+smesh-5, 11*2, 8*2};
         SDL_Point rotPoint_eli = {((80*5) / 3), ( (22*3) / 2)};

        SDL_RenderCopyEx(renderer, live_bar_el_prison, NULL, &live_bar_el_prisoner_rect, 90, &rotPoint_eli, SDL_FLIP_NONE);
    }
    if(hp_prisoner<=0)
    {
        svoboda=false;
        texture_zalosh=texture_zalosh_dead;
    }else
    if(svoboda==false)
    {
        texture_zalosh=texture_zalosh_passive;
    }else
    if(svoboda==true)
    {
        texture_zalosh=texture_zalosh_active;
    }
    if ( ((player.get_xpos()<x_pos+50 && player.get_ypos()<y_pos+50)&& (player.get_xpos()>x_pos-50 && player.get_ypos()>y_pos-50) ) && p==true && hp_prisoner>0 && !svoboda)
    {
        rand_spawn(0, 10);
        svoboda=true;
    }
//////////move
    if(svoboda==false && hp_prisoner>0)
    {
        angle=(atan2(player.get_ypos()-y_pos, player.get_xpos()-x_pos)*180.0000)/3.1416;
        angle2=(atan2(player.get_ypos()-y_pos, player.get_xpos()-x_pos));
    }
    if(svoboda==true && hp_prisoner>0)
    {
        angle=(atan2(player.get_ypos()-y_pos, player.get_xpos()-x_pos)*180.0000)/3.1416;
        angle2=(atan2(player.get_ypos()-y_pos, player.get_xpos()-x_pos));
        if(finel_vert==true)
            {
                x_pos = x_pos + speed*cos(angle2)/2;
                y_pos = y_pos + speed*sin(angle2)/2;
            }
        if (is_collision_pl(x_pos,y_pos,x_size-10,y_size-10)==true)
        {
            if(finel_vert==true)
            {
                x_pos = x_pos - speed*cos(angle2)/2;
                y_pos = y_pos - speed*sin(angle2)/2;
            }

        }
    }
    //3159,500
    //x_pos=3159;
        //y_pos=500;
////        3184 1130
    if(x_pos>3159-200 && y_pos>800 && y_pos<1300)
    {
        x_pos=3159;
        y_pos=1130;
        finel_vert=false;
    }
////finish move
    screen_x=convert_x_to_screen(x_pos);
    screen_y=convert_y_to_screen(y_pos);

    SDL_Rect dstrect = {screen_x-x_size/2, screen_y-y_size/2, x_size, y_size};
    SDL_Point rotPoint = {(x_size / 2), (y_size / 2)};

    SDL_RenderCopyEx(renderer, texture_zalosh, NULL, &dstrect, angle-90, &rotPoint, SDL_FLIP_HORIZONTAL);
//////render
}
int Prisoner::get_xpos(){return x_pos;}
int Prisoner::get_ypos(){return y_pos;}
