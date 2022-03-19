#include "GAME.h"

int tile_size = 48;
int map_chunk_w = 198;
int map_chunk_h = 173;
Player player;

Scene scene;
Prisoner prisoner;

bool l=true;
bool r=true;
bool p=true;
bool game, game_music;

SDL_Texture* texture_bullet;
SDL_Texture* texture_Bot_robots;
SDL_Texture* texture_vzryv;
SDL_Texture* player_automat_passive;

SDL_Surface* image_bullet;
SDL_Texture* automat_bullet;
SDL_Texture* rpg_bullet;
SDL_Texture* pistol_bullet;

SDL_Surface* image;
SDL_Texture* tex;
SDL_Texture* backgr;
SDL_Texture* tex1;
SDL_Texture* tex2;
SDL_Texture* fon;
SDL_Surface* curs;
SDL_Texture* arrow;
SDL_Texture* act_arrow;
SDL_Texture* fact;
SDL_Texture* logo;
SDL_Texture* logo_text;
SDL_Texture* about_text;
SDL_Cursor* cursor;

Gallery gallery;
Button start, start_level;
Button exit1;
Button r_arrow, l_arrow;

Mix_Music* musc;
Mix_Music* about_mus;


vector<Gun_item>Gun_items;
vector<Bot_tank> Bot_tanks;
vector<Bullet>bullets;
vector<Bot_robot>Bot_robots;
vector <Vzryv> Vzryvs;

void rand_spawn(int count_items, int count_bots)
{
    double x,y;
    for(int i=0;i<count_items;i++)
    {
        x=rand()%(map_chunk_w-1);
        y=rand()%(map_chunk_h-1);
        while(is_collision_chunk(x,y)==true)
        {
            x=rand()%(map_chunk_w-1);
            y=rand()%(map_chunk_h-1);
        }
        Gun_items.push_back(Gun_item(x*tile_size,y*tile_size,42*2,42*2,texture_Bot_robots,1+rand()%5));
    }
    for(int i=0;i<count_bots;i++)
    {
        x=rand()%(map_chunk_w-1);
        y=rand()%(map_chunk_h-1);
        while(is_collision_chunk(x,y)==true)
        {
            x=rand()%(map_chunk_w-1);
            y=rand()%(map_chunk_h-1);
        }
        Bot_robots.push_back(Bot_robot(x*tile_size,y*tile_size,96,96,texture_Bot_robots,1));
    }
}

void load_textures1(SDL_Renderer* renderer, vector<SDL_Texture*> &mass){
    SDL_Texture* cadr;
    string thr = ".png";
    string sec, fir = "about\\", file;
    for(int i = 1; i < 49; i++){
        sec = to_string(i);
        file = fir + sec + thr;
        texture_from_image(renderer, cadr, image, file);
        mass.push_back(cadr);
    }
}

void load_textures(SDL_Renderer* renderer, vector<SDL_Texture*> &mass){
    SDL_Texture* cadr;
    string thr = ".jpg";
    string sec, fir = "Textures_load\\", file;
    for(int i = 0; i < 151; i++){
        sec = to_string(i);
        file = fir + sec + thr;
        texture_from_image(renderer, cadr, image, file);
        mass.push_back(cadr);
    }
}

void about_screen(SDL_Renderer* renderer, SDL_Event event){
    vector <SDL_Texture*> load;
    load_textures1(renderer, load);
    int repeat = 0;
    Mix_PlayMusic(about_mus, -1);
    while(repeat < 8){
        for(int i = 0; i < 48; i++){
            SDL_PollEvent(&event);
            SDL_RenderClear(renderer);
            render_texture(renderer, load[i], 0, 0, win_w, win_h);
            render_texture(renderer, about_text, win_w / 2 - 932, win_h / 2 + 300, 1532, 202);
            SDL_Delay(60);
            SDL_RenderPresent(renderer);
        }
        repeat++;
    }
}

void present_screen(SDL_Renderer* renderer, SDL_Event event){
    vector <SDL_Texture*> load;
    load_textures(renderer, load);

    int xs = 0, ys = 0;
    texture_from_image(renderer, logo, image, "Textures\\MainMenu\\potato_engine.png");
    texture_from_image(renderer, logo_text, image, "Textures\\MainMenu\\potat2.png");
    Mix_Chunk* potat = Mix_LoadWAV("Sounds\\epic_logo_potat.wav");
    Mix_Chunk* botic = Mix_LoadWAV("Sounds\\botic_effect.wav");
    for(int i = 0; i < 150; i++){
        SDL_PollEvent(&event);
        SDL_RenderClear(renderer);
        render_texture(renderer, load[i], 0, 0, win_w, win_h);
        if(i < 66){
            xs += 4, ys += 4;
        }
        if(i == 0) Mix_PlayChannel(0, potat, 0);
        render_texture(renderer, logo, win_w / 2 - xs / 2, win_h / 2 - ys, xs, ys);
        if(i >= 66){
            render_texture(renderer, logo_text, win_w / 2 - 140, win_h / 2 + 23, 280, 112);
        }
        SDL_Delay(60);
        SDL_RenderPresent(renderer);
    }
    texture_from_image(renderer, logo, image, "Textures\\MainMenu\\botici_logo.png");
    texture_from_image(renderer, logo_text, image, "Textures\\MainMenu\\botici_text.png");
    xs = 0, ys = 0;
    for(int i = 0; i < 150; i++){
        SDL_PollEvent(&event);
        SDL_RenderClear(renderer);
        render_texture(renderer, load[i], 0, 0, win_w, win_h);
        if(i < 66){
            xs += 4, ys += 4;
        }
        if(i == 0) Mix_PlayChannel(0, botic, 0);
        render_texture(renderer, logo, win_w / 2 - xs / 2, win_h / 2 - ys, xs, ys);
        if(i >= 66){
            render_texture(renderer, logo_text, win_w / 2 - 108, win_h / 2 + 23, 216, 40);
        }
        SDL_Delay(60);
        SDL_RenderPresent(renderer);
    }
}

void inichialization_factory()
{
    player.lives_bar = 100;
    for (int i=Gun_items.size()-1;i>=0;i--){
    Gun_items.erase(Gun_items.begin()+i);
    }
    for (int i=Bot_tanks.size()-1;i>=0;i--){
    Bot_tanks.erase(Bot_tanks.begin()+i);
    }
    for (int i=Bot_robots.size()-1;i>=0;i--){
    Bot_robots.erase(Bot_robots.begin()+i);
    }
    for (int i=bullets.size()-1;i>=0;i--){
    bullets.erase(bullets.begin()+i);
    }
    prisoner = Prisoner(1300,1300,96,96);
    int d=rand()%21;
    if(d==1)
    {
       prisoner.x_pos=7448;
       prisoner.y_pos=2369;
       player.x_pos = 2838;
       player.y_pos= 7650;
    }else if(d==2)
    {
       player.x_pos=7448;
       player.y_pos=2369;
       prisoner.x_pos = 2838;
       prisoner.y_pos= 7650;
    }else if(d==3)
    {
       player.x_pos=5484;
       player.y_pos=2778;
       prisoner.x_pos = 8047;
       prisoner.y_pos= 8096;
    }else if(d==4)
    {
       prisoner.x_pos=5484;
       prisoner.y_pos=2778;
       player.x_pos = 8047;
       player.y_pos= 8096;
    }else if(d==5)
    {
       player.x_pos=7247;
       player.y_pos=7605;
       prisoner.x_pos = 3252;
       prisoner.y_pos= 2774;
    }else if(d==6)
    {
       prisoner.x_pos=7247;
       prisoner.y_pos=7605;
       player.x_pos = 3252;
       player.y_pos= 2774;
    }else if(d==7)
    {
       prisoner.x_pos=7743;
       prisoner.y_pos=4823;
       player.x_pos = 9172;
       player.y_pos= 7684;
    }else if(d==8)
    {
       player.x_pos=7743;
       player.y_pos=4823;
       prisoner.x_pos = 9172;
       prisoner.y_pos= 7684;
    }
    else if(d==9)
    {
       prisoner.x_pos=7743;
       prisoner.y_pos=4823;
       player.x_pos = 9172;
       player.y_pos= 7684;
    }else if(d==10)
    {
       player.x_pos=7743;
       player.y_pos=4823;
       prisoner.x_pos = 9172;
       prisoner.y_pos= 7684;
    }else if(d==11)
    {
       prisoner.x_pos=6096;
       prisoner.y_pos=6818;
       player.x_pos = 7676;
       player.y_pos= 5413;
    }else if(d==12)
    {
       player.x_pos=6096;
       player.y_pos=6818;
       prisoner.x_pos = 7676;
       prisoner.y_pos= 5413;
    }else if(d==13)
    {
       prisoner.x_pos=8100;
       prisoner.y_pos=3200;
       player.x_pos = 6616;
       player.y_pos= 2717;
    }else if(d==14)
    {
       player.x_pos=8100;
       player.y_pos=3200;
       prisoner.x_pos = 6616;
       prisoner.y_pos= 2717;
    }
    else if(d==15)
    {
       prisoner.x_pos=5997;
       prisoner.y_pos=2429;
       player.x_pos = 8469;
       player.y_pos= 2049;
    }else if(d==16)
    {
       player.x_pos=5997;
       player.y_pos=2429;
       prisoner.x_pos = 8469;
       prisoner.y_pos= 2049;
    }else if(d==17)
    {
       prisoner.x_pos=3164;
       prisoner.y_pos=3604;
       player.x_pos = 8689;
       player.y_pos= 6176;
    }else if(d==18)
    {
       player.x_pos=3164;
       player.y_pos=3604;
       prisoner.x_pos = 8689;
       prisoner.y_pos= 6176;
    }else if(d==19)
    {
       prisoner.x_pos=4658;
       prisoner.y_pos=2998;
       player.x_pos = 8160;
       player.y_pos = 5882 ;
    }else if(d==20)
    {
       player.x_pos=4658;
       player.y_pos=2998;
       prisoner.x_pos = 8160;
       prisoner.y_pos = 5882 ;
    }
    Bot_tanks.push_back(Bot_tank(900,400,33*4,32*4,1,0));
    Bot_tanks.push_back(Bot_tank(1742,1869,33*4,32*4,1,1));
    Bot_tanks.push_back(Bot_tank(1742,1869,33*4,32*4,1,3));
    Bot_tanks.push_back(Bot_tank(1742,1869,33*4,32*4,1,4));

    //player.x_pos = 2000;//*
    //player.y_pos = 1500;//*

    player.set_gun_type(0);
    player.Kol_patronov=0;

    //player.x_pos = 8300;
    //player.y_pos = 8000;
    //prisoner.x_pos = 2000;//*
    //prisoner.y_pos = 1000;//*
    prisoner.svoboda=false;
    player.bot_kill=0;
    player.shield=false;
    prisoner.hp_prisoner=100;
    rand_spawn(50,20);
    player.set_texture(tex);
}

void init_menu(SDL_Renderer* renderer){
    texture_from_image(renderer, tex1, image, "Textures\\MainMenu\\START.png");
    texture_from_image(renderer, tex2, image, "Textures\\MainMenu\\STARTLIGHT.png");
    start = Button(tex1, tex2, 405, 450, 325, 90, 375, 140, 0);

    texture_from_image(renderer, tex1, image, "Textures\\MainMenu\\START.png");
    texture_from_image(renderer, tex2, image, "Textures\\MainMenu\\STARTLIGHT.png");
    start_level = Button(tex1, tex2, win_w / 2 - 162, win_h / 2 + 300, 325, 90, 375, 140, 0);

    texture_from_image(renderer, tex1, image, "Textures\\MainMenu\\EXIT.png");
    texture_from_image(renderer, tex2, image, "Textures\\MainMenu\\EXITLIGHT.png");
    exit1 = Button(tex1, tex2, 452, 600, 230, 90, 280, 140, 200);

    texture_from_image(renderer, arrow, image, "Textures\\arrow.png");
    texture_from_image(renderer, act_arrow, image, "Textures\\arrow_r_active.png");
    r_arrow = Button(arrow, act_arrow, win_w / 2 + 400, win_h /2 - 40, 80, 80, 80, 80, 200);

    texture_from_image(renderer, arrow, image, "Textures\\arrow_l.png");
    texture_from_image(renderer, act_arrow, image, "Textures\\arrow_l_active.png");
    l_arrow = Button(arrow, act_arrow, win_w / 2 - 480, win_h /2 - 40, 80, 80, 80, 80, 200);

    gallery = Gallery(r_arrow, l_arrow);

    texture_from_image(renderer, fact, image, "Textures\\factory_el.png");
    Element factory(fact, win_w / 2 - 362, win_h / 2 - 375, 725, 630, "factory");

    texture_from_image(renderer, fact, image, "Textures\\MainMenu\\el_null.png");
    Element home(fact, win_w / 2 - 340, win_h / 2 - 245, 680, 490, "home");

    gallery.add_element(factory);
    gallery.add_element(home);

    texture_from_image(renderer, tex1, image, "Textures\\MainMenu\\FON2.png");
    texture_from_image(renderer, tex2, image, "Textures\\MainMenu\\LOGO_3.png");
    texture_from_image(renderer, fon, image, "Textures\\MainMenu\\FON_LEVEL_2.png");
    curs = IMG_Load("Textures\\cursor.png");
    cursor = SDL_CreateColorCursor(curs, 0, 0);
}

void Game(SDL_Renderer* renderer){
    cout << win_w << "|" << win_h;
    int result = Mix_OpenAudio(44100, AUDIO_S16SYS, 2, 512);

    musc = Mix_LoadMUS("Sounds\\MainMenuTheme.wav");
    Mix_Music* musc2 = Mix_LoadMUS("Sounds\\Fight_Mus.wav");
    Mix_Music* over = Mix_LoadMUS("Sounds\\game_over.wav");
    about_mus = Mix_LoadMUS("Sounds\\about_mus.wav");

    SDL_Event event;
    bool quit = false, main_music = false, level_menu = false;

    texture_from_image(renderer, tex, image, "Textures\\player_1.png");
    texture_from_image(renderer, backgr, image, "Textures\\factory_map.png");
    player = Player(tex, 2000, 2000, 96, 96);
    Helicopter helicopter = Helicopter(3159,500,80*6,178*6);
    prisoner = Prisoner(1300,1300,96,96);
    //Bot_tanks.push_back(Bot_tank(900,400,33*4,32*4,1,0));
    scene = Scene(backgr);
    scene.set_colis_map("Textures\\factory_colis_map.txt");
    scene.x_size = tile_size * map_chunk_w;
    scene.y_size = tile_size * map_chunk_h;

//inichialization
    texture_from_image(renderer, texture_bullet, image_bullet, "Textures\\Pistol_bullet.png");
    texture_from_image(renderer, texture_Bot_robots, image_bullet, "Textures\\bot_active.png");
    texture_from_image(renderer, texture_vzryv, image, "Textures\\pngwing.com.png");

    texture_from_image(renderer, player_automat_passive, image, "Textures\\player_avtomat.png");

    texture_from_image(renderer, pistol_bullet, image_bullet, "Textures\\Pistol_bullet.png");
    texture_from_image(renderer, automat_bullet, image_bullet, "Textures\\Automat_bullet.png");
    texture_from_image(renderer, rpg_bullet, image_bullet, "Textures\\RPG_bullet.png");

    present_screen(renderer, event);
    init_menu(renderer);
    User_Interface UI_obj = User_Interface(0,0,rpg_bullet);
    SDL_SetCursor(cursor);
    Mix_PlayMusic(musc, -1);
    Mix_VolumeMusic(20);

    texture_from_image(renderer, logo, image, "Textures\\MainMenu\\game_over.png");
    texture_from_image(renderer, logo_text, image, "Textures\\MainMenu\\win.png");
    texture_from_image(renderer, about_text, image, "\Textures\\MainMenu\\about_text.png");

    while(!quit){
        SDL_RenderClear(renderer);
        SDL_PollEvent(&event);
        switch (event.type){
        case SDL_QUIT:
            quit = true;
            break;
        case SDL_MOUSEBUTTONDOWN:
            if(start.click()) level_menu = true;
            if(exit1.click()) quit = true;
            break;
        }
        render_texture(renderer, tex1, 0, 0, win_w, win_h);
        render_texture(renderer, tex2, 350, 50, 425, 340);
        start.update(renderer);
        exit1.update(renderer);
        while(!quit && level_menu){
            SDL_RenderClear(renderer);
            SDL_PollEvent(&event);
            switch (event.type){
            case SDL_QUIT:
                quit = true;
                break;
            case SDL_MOUSEBUTTONDOWN:
                if(start_level.click()){
                    game = true;
                    about_screen(renderer, event);
                    Mix_PlayMusic(musc2,-1);
                }
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {
                case SDLK_ESCAPE:
                    level_menu = false;
                    break;
                }
            }
            render_texture(renderer, fon, 0, 0, win_w, win_h);
            gallery.gallery_update(renderer);
            start_level.update(renderer);

            while(!quit && game){
                if(!game_music){
                    inichialization_factory();
                    game_music = true;
                }
                SDL_RenderClear(renderer);
                SDL_PollEvent(&event);
                switch (event.type){
                case SDL_QUIT:
                    quit = true;
                    break;
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        game = false;
                        game_music = false;
                        Mix_PlayMusic(musc,-1);
                        SDL_Delay(300);
                        break;
                    }
                }
                SDL_Delay(1);
                scene.update_scene(renderer);

                for (int i=Gun_items.size()-1;i>=0;i--){
                    if (Gun_items[i].live) {//Gun_items[i].live
                        Gun_items[i].pick_up_gun(renderer,p);
                        //p=false;
                    } else {
                        Gun_items.erase(Gun_items.begin()+i);
                    }
                    }
                for (int i=Vzryvs.size()-1;i>=0;i--){
                    if (Vzryvs[i].live) {//Gun_items[i].live
                        Vzryvs[i].update_vzryv(renderer);
                        //p=false;
                    } else {
                        Vzryvs.erase(Vzryvs.begin()+i);
                    }
                    }
                for (int i=bullets.size()-1;i>=0;i--){
                    if (bullets[i].live) {
                        bullets[i].move_bullet(renderer);
                    } else {
                        bullets.erase(bullets.begin()+i);
                    }
                }
                for (int i=Bot_robots.size()-1;i>=0;i--){
                    if (Bot_robots[i].live) {
                        Bot_robots[i].move_Bot_robot(renderer);
                    } else {
                        Bot_robots.erase(Bot_robots.begin()+i);
                    }
                }
                for (int i=Bot_tanks.size()-1;i>=0;i--){
                    if (Bot_tanks[i].live) {
                        Bot_tanks[i].move_Bot_tank(renderer);
                    } else {
                        Bot_tanks.erase(Bot_tanks.begin()+i);
                    }
                }

                //bot_tank.move_Bot_tank(renderer);
                if(player.lives_bar<=0)
                {
                    game = false;
                    game_music = false;
                    Mix_VolumeMusic(0);
                    for(int i = 0; i < 2000; i++){
                        if(i == 300) Mix_VolumeMusic(128), Mix_PlayMusic(over, 0);
                        SDL_Delay(1);
                        render_texture(renderer, logo, win_w / 2 - 264, win_h / 2 - 162, 528, 324);
                        SDL_RenderPresent(renderer);
                    }
                    Mix_PlayMusic(musc,-1);
                }
                if(prisoner.hp_prisoner <= 0)
                {
                    game = false;
                    game_music = false;
                    Mix_VolumeMusic(0);
                    for(int i = 0; i < 2000; i++){
                        if(i == 300) Mix_VolumeMusic(128), Mix_PlayMusic(over, 0);
                        SDL_Delay(1);
                        render_texture(renderer, logo, win_w / 2 - 264, win_h / 2 - 162, 528, 324);
                        SDL_RenderPresent(renderer);
                    }
                    Mix_VolumeMusic(20);
                    Mix_PlayMusic(musc,-1);
                }
                prisoner.update(renderer);
                player.update(renderer);
                UI_obj.Update_UI(renderer);
                helicopter.update(renderer);

                SDL_RenderPresent(renderer);
            }
            SDL_RenderPresent(renderer);
        }
        SDL_RenderPresent(renderer);
    }
    Mix_CloseAudio();
}
