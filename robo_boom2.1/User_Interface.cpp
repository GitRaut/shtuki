#include "GAME.h"
#include "User_Interface.h"

SDL_Texture* live_bar_kontur;
SDL_Texture* live_bar_el;
SDL_Texture* krov_ef;
vector<SDL_Texture*> numb_text;
vector<SDL_Texture*> anim_moln;
SDL_Texture* tex_n;
SDL_Texture* tex_load;

SDL_Texture* icon_avt;
SDL_Texture* pist_icon;
SDL_Texture* rpg_icon;
SDL_Texture* bot_icon;
void print_num_screen(int x,int y, int n,SDL_Renderer* renderer)
{
    int k=3;


    SDL_Rect numb = {x, y, 10*3, 14*3};
    //SDL_Point num_p = {((10*k) / 2), ( (14*k) / 2)};
    if(n==0)
    {
        SDL_RenderCopy(renderer, numb_text[0], NULL, &numb);
    }else if(n==1)
    {
        SDL_RenderCopy(renderer, numb_text[1], NULL, &numb);
    }else if(n==2)
    {
        SDL_RenderCopy(renderer, numb_text[2], NULL, &numb);
    }else if(n==3)
    {
        SDL_RenderCopy(renderer, numb_text[3], NULL, &numb);
    }else if(n==4)
    {
        SDL_RenderCopy(renderer, numb_text[4], NULL, &numb);
    }else if(n==5)
    {
        SDL_RenderCopy(renderer, numb_text[5], NULL, &numb);
    }else if(n==6)
    {
        SDL_RenderCopy(renderer, numb_text[6], NULL, &numb);
    }else if(n==7)
    {
        SDL_RenderCopy(renderer, numb_text[7], NULL, &numb);
    }else if(n==8)
    {
        SDL_RenderCopy(renderer, numb_text[8], NULL, &numb);
    }else if(n==9)
    {
        SDL_RenderCopy(renderer, numb_text[9], NULL, &numb);
    }

}

User_Interface::User_Interface(int width, int height, SDL_Texture* tex){
    x_size = width;
    y_size = height;
    texture = tex;
    live = true;

}

void User_Interface::Update_UI(SDL_Renderer* renderer)
{
    if(start==true)
    {//krov_effect.png
        texture_from_image(renderer, live_bar_kontur, image, "Textures\\lifebar_2.png");
        texture_from_image(renderer, krov_ef, image, "Textures\\krov_effect.png");
        //sl_kr.png
        texture_from_image(renderer, live_bar_el, image, "Textures\\life_bar_el.png");

        texture_from_image(renderer, icon_avt, image, "Textures\\icon_avt.png");
        texture_from_image(renderer, pist_icon, image, "Textures\\pist_icon.png");
        texture_from_image(renderer, rpg_icon, image, "Textures\\rpg_icon.png");
        texture_from_image(renderer, bot_icon, image, "Textures\\bot_icon.png");

        /////numbers
        ////*

        texture_from_image(renderer, tex_load, image, "Texture_numbers\\0.png");
        numb_text.push_back(tex_load);
        texture_from_image(renderer, tex_load, image, "Texture_numbers\\1.png");
        numb_text.push_back(tex_load);
        texture_from_image(renderer, tex_load, image, "Texture_numbers\\2.png");
        numb_text.push_back(tex_load);
        texture_from_image(renderer, tex_load, image, "Texture_numbers\\3.png");
        numb_text.push_back(tex_load);
        texture_from_image(renderer, tex_load, image, "Texture_numbers\\4.png");
        numb_text.push_back(tex_load);
        texture_from_image(renderer, tex_load, image, "Texture_numbers\\5.png");
        numb_text.push_back(tex_load);
        texture_from_image(renderer, tex_load, image, "Texture_numbers\\6.png");
        numb_text.push_back(tex_load);
        texture_from_image(renderer, tex_load, image, "Texture_numbers\\7.png");
        numb_text.push_back(tex_load);
        texture_from_image(renderer, tex_load, image, "Texture_numbers\\8.png");
        numb_text.push_back(tex_load);
        texture_from_image(renderer, tex_load, image, "Texture_numbers\\9.png");
        numb_text.push_back(tex_load);

        texture_from_image(renderer, tex_load, image, "Textures_icon_moln\\1.png");
        anim_moln.push_back(tex_load);
        texture_from_image(renderer, tex_load, image, "Textures_icon_moln\\2.png");
        anim_moln.push_back(tex_load);
        texture_from_image(renderer, tex_load, image, "Textures_icon_moln\\3.png");
        anim_moln.push_back(tex_load);
        texture_from_image(renderer, tex_load, image, "Textures_icon_moln\\4.png");
        anim_moln.push_back(tex_load);
        texture_from_image(renderer, tex_load, image, "Textures_icon_moln\\5.png");
        anim_moln.push_back(tex_load);
        texture_from_image(renderer, tex_load, image, "Textures_icon_moln\\6.png");
        anim_moln.push_back(tex_load);
        texture_from_image(renderer, tex_load, image, "Textures_icon_moln\\7.png");
        anim_moln.push_back(tex_load);
        texture_from_image(renderer, tex_load, image, "Textures_icon_moln\\8.png");
        anim_moln.push_back(tex_load);
        texture_from_image(renderer, tex_load, image, "Textures_icon_moln\\9.png");
        anim_moln.push_back(tex_load);
        texture_from_image(renderer, tex_load, image, "Textures_icon_moln\\10.png");
        anim_moln.push_back(tex_load);
        texture_from_image(renderer, tex_load, image, "Textures_icon_moln\\11.png");
        anim_moln.push_back(tex_load);

        ////
        start=false;
    }
     pl_life=player.lives_bar;
     pl_bullets=player.Kol_patronov;
     pl_gun_type=player.get_gun_type();
     pl_kool_down_bot=player.kool_down_null_comm/100;
     kol_bot=player.bot_kill;
     smesh=0;
     for(int i=0;i<pl_life/10;i++)
     {   smesh+=23;
         SDL_Rect live_bar_el_rect = {1250+smesh-1180, 735-691, 11*4, 8*4};
         SDL_Point rotPoint_el = {((80*5) / 3), ( (22*3) / 2)};

        SDL_RenderCopyEx(renderer, live_bar_el, NULL, &live_bar_el_rect, 0, &rotPoint_el, SDL_FLIP_NONE);
     }
     if(time_krov>0) time_krov--;
     if(time_back_krov>0) time_back_krov--;
     if(pl_life<40  && time_krov==0)
     {

         if(time_krov_vis==false)
         {
           time_back_krov=400;
           time_krov_vis=true;
         }
         if(time_back_krov>0)
         {
            //SDL_Rect krov = {200, 0, 2838, 1295};
            SDL_Rect krov = {0, -100, 1920, 1080};
           SDL_Point rotPoint_krov = {((2838*1) / 3), ( (1295*1) / 2)};

           SDL_RenderCopyEx(renderer, krov_ef, NULL, &krov, 180, &rotPoint_krov, SDL_FLIP_HORIZONTAL);
         }

     }
     if(time_back_krov==0 && time_krov== 0)
     {
         time_krov_vis=false;
         time_krov=600;
     }

    SDL_Rect type_gun_icon = {1200+smesh, 710, 11*4, 8*4};
    SDL_Point rotPoint_icon_gun = {((80*5) / 3), ( (22*3) / 2)};
    if(pl_gun_type==1)
    {
        SDL_Rect type_gun_icon = {win_w-win_w/10, win_h-100, 18*4, 10*4};
        //SDL_Rect type_gun_icon = {win_w/2+win_w/4, win_h/2+win_w/5, 18*4, 10*4};
        SDL_RenderCopyEx(renderer, pist_icon, NULL, &type_gun_icon, 0, &rotPoint_icon_gun, SDL_FLIP_NONE);
    }
    if(pl_gun_type==2)
    {
        SDL_Rect type_gun_icon = {win_w-win_w/10, win_h-130, 32*4, 16*4};
        //SDL_Rect type_gun_icon = {win_w/2+win_w/4, win_h/2+win_w/5, 32*4, 16*4};
        SDL_RenderCopyEx(renderer, icon_avt, NULL, &type_gun_icon, 0, &rotPoint_icon_gun, SDL_FLIP_NONE);
    }
    if(pl_gun_type==3)
    {
        SDL_Rect type_gun_icon = {win_w-win_w/10, win_h-120, 37*4, 10*4};
        //SDL_Rect type_gun_icon = {win_w/2+win_w/4, win_h/2+win_w/5, 37*4, 10*4};
        SDL_RenderCopyEx(renderer, rpg_icon, NULL, &type_gun_icon, 0, &rotPoint_icon_gun, SDL_FLIP_NONE);
    }
    if(pl_bullets<9)
    {
        print_num_screen(win_w-win_w/10+100, win_h-50,pl_bullets,renderer);
        //print_num_screen(win_w/2+win_w/4, win_h/2+win_w/5,pl_bullets,renderer);
    }else
    {
        print_num_screen(win_w-win_w/10+100, win_h-50,pl_bullets%10,renderer);
        //print_num_screen(win_w/2+win_w/4, win_h/2+win_w/5,pl_bullets%10,renderer);
        pl_bullets=pl_bullets/10;
        print_num_screen(win_w-win_w/10-40+100, win_h-50,pl_bullets,renderer);
        //print_num_screen(win_w/2+win_w/4-40, win_h/2+win_w/5,pl_bullets,renderer);
    }

    if(kol_bot<9)
    {
        print_num_screen(win_w-win_w/10, win_h/2-win_w/5+100,kol_bot,renderer);
        //print_num_screen(win_w/2+win_w/4-40, win_h/2+win_w/5,kol_bot,renderer);
    }else
    {
        print_num_screen(win_w-win_w/10, win_h/2-win_w/5+50,kol_bot%10,renderer);
        //print_num_screen(win_w/2+win_w/4-40, win_h/2+win_w/5,kol_bot%10,renderer);
        kol_bot=kol_bot/10;
        print_num_screen(win_w-win_w/10-40, win_h/2-win_w/5+50,kol_bot,renderer);
        //print_num_screen(win_w/2+win_w/4-40, win_h/2+win_w/5,kol_bot,renderer);
    }
    anim_m_stad=(50-pl_kool_down_bot)/5;
    if(pl_kool_down_bot==0)
    {
        anim_m_stad=10;
    }
    if(pl_kool_down_bot<9)
    {
        print_num_screen(155, 720,pl_kool_down_bot,renderer);
        //anim_m_stad++;
    }else
    {
        //print_num_screen(1355, 790,pl_bullets,renderer);
        print_num_screen(155, 720,pl_kool_down_bot%10,renderer);
        pl_kool_down_bot=pl_kool_down_bot/10;
        print_num_screen(155-40, 720,pl_kool_down_bot,renderer);
    }

    SDL_Rect lf = {win_w-win_w/10, win_h/2-win_w/5, 26*2, 29*2};

    SDL_Point lfr = {((80*5) / 3), ( (22*3) / 2)};
    SDL_RenderCopyEx(renderer, bot_icon, NULL, &lf, 0, &lfr, SDL_FLIP_NONE);

    SDL_Rect live_bar_kontur_rect = {1200-1180, 700-690, 80*4, 22*4};
    SDL_Point rotPoint = {((80*5) / 3), ( (22*3) / 2)};

    SDL_RenderCopyEx(renderer, live_bar_kontur, NULL, &live_bar_kontur_rect, 0, &rotPoint, SDL_FLIP_NONE);


////////moln_ymeniye
    SDL_Rect mol_rect = {20, 700, 26*3, 29*3};

    SDL_Point moln_rot = {((80*5) / 3), ( (22*3) / 2)};
    SDL_RenderCopyEx(renderer, anim_moln[anim_m_stad], NULL, &mol_rect, 0, &moln_rot, SDL_FLIP_NONE);

}
