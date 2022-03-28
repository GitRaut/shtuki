#include "Helicopter.h"
#include "GAME.h"
SDL_Texture* texture_vint;
extern Prisoner prisoner;
SDL_Texture* texture_body;
Helicopter::Helicopter(){};
Helicopter::Helicopter(int x, int y, int w, int h){
    x_pos = x;
    y_pos = y-3000;
    x_size = w;
    y_size = h;
}
void Helicopter::update(SDL_Renderer* renderer){
    if(texxt==true)
    {
        texxt=false;
        texture_from_image(renderer, texture_body, image, "Textures\\modern_helic.png");
        texture_from_image(renderer, texture_vint, image, "Textures\\helic_propeller.png");
    }
    screen_x=convert_x_to_screen(x_pos);
    screen_y=convert_y_to_screen(y_pos);
    SDL_Rect vert_rect = {screen_x, screen_y, x_size, y_size};
    SDL_Point vert_rot = {(x_size/2), (y_size/2)};

    SDL_RenderCopyEx(renderer, texture_body, NULL, &vert_rect, 90, &vert_rot, SDL_FLIP_HORIZONTAL);
    ///////////////////////////////////////
    angle_vint+=20;
    if(angle_vint>=360){angle_vint=0;}
    if(time_polet>0)time_polet--;
    if(prisoner.finel_vert==false)
    {
        if(time_polet==-1)
        {
            time_polet=10000;
            polet=true;
        }

    }
    if(time_polet>0)
    {
        if(!let){
            Mix_PlayMusic(fly, 0);
            let = true;
        }
        if(y_pos<500){
            y_pos+=0.5;
        }
       // angle=0;
    }

    SDL_Rect vint_rect = {screen_x-x_size-50, screen_y-40, 1147, 1147};
    SDL_Point vint_rot = {(1147/2), (1147/2)};

    SDL_RenderCopyEx(renderer, texture_vint, NULL, &vint_rect, angle_vint, &vint_rot, SDL_FLIP_HORIZONTAL);

    if(y_pos>=500)
    {
        Mix_PlayMusic(win, 0);
        game = false;
        game_music = false;
        let = false;
        for(int i = 0; i < 4000; i++){
            SDL_Delay(1);
            render_texture(renderer, logo_text, win_w / 2 - 228, win_h / 2 - 78, 456, 156);
            SDL_RenderPresent(renderer);
        }
        Mix_PlayMusic(musc,-1);
    }
}
