#include <iostream>
#include <vector>
#include <windows.h>
#include <SDL.h>
#define WINDOW_WIDTH 600

using namespace std;

int win_w;
int win_h;
int mouse_x = -1;
int mouse_y = -1;
int r = 0, g = 0, b = 0;
int cz_timer = 80, timer = 80;
int scale = 10;
SDL_Window* win;
SDL_Renderer* renderer;

void render_window(int &win_width, int &win_height){
    SDL_DisplayMode DM;
    SDL_GetDesktopDisplayMode(0, &DM);
    win_width = DM.w;
    win_height = DM.h - 20;
    win = SDL_CreateWindow("GAME", 0, 20, win_w, win_h, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer( win, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
}

void control(vector <int> &pos_x, vector <int> &pos_y, vector <int> &scales){
    cz_timer--;
    timer--;
    if(GetAsyncKeyState(VK_CONTROL) && GetAsyncKeyState('Z') && pos_x.size() > 0 && cz_timer <= 0){
        pos_x.pop_back();
        pos_y.pop_back();
        scales.pop_back();
        cz_timer = 80;
    }
    if(GetAsyncKeyState(VK_UP) && timer <= 0){
        scale += 10;
        timer = 80;
    }
    if(GetAsyncKeyState(VK_DOWN) && timer <= 0 && scale >= 20){
        scale -= 10;
        timer = 80;
    }
}

void update_color(){
    if(GetAsyncKeyState('L')){
         r = 255;
         g = 255;
         b = 255;
    }
    else if(GetAsyncKeyState('B')){
         r = 0;
         g = 0;
         b = 0;
    }
}

void draw(vector <int> pos_x, vector <int> pos_y, vector <int> red, vector <int> green, vector <int> blue, vector <int> scales){
    for(int i = 0; i < pos_x.size(); i++){
        SDL_SetRenderDrawColor(renderer, red[i], green[i], blue[i], 255);
        SDL_Rect rect = {pos_x[i] * scales[i], pos_y[i] * scales[i], scales[i], scales[i]};
        SDL_RenderFillRect(renderer, &rect);
    }
}

int main(int argc, char** args) {
    SDL_Init(SDL_INIT_EVERYTHING);
    render_window(win_w, win_h);
    SDL_Event event;
    bool quit = false, is_draw = false;
    int prev_x = -1, prev_y = -1;
    vector <int> pos_x, pos_y, scales;
    vector <int> red, green, blue;
    while(!quit){
        SDL_Delay(1);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);
        SDL_PollEvent(&event);
        switch (event.type){
        case SDL_QUIT:
            quit = true;
            break;
        }
        is_draw = false;
        if(GetAsyncKeyState(VK_LBUTTON))
            is_draw = true;
        if(is_draw){
            SDL_GetMouseState(&mouse_x, &mouse_y);
            if(mouse_x / scale != prev_x || mouse_y / scale != prev_y){
                pos_x.push_back(mouse_x / scale);
                pos_y.push_back(mouse_y / scale);
                scales.push_back(scale);
                red.push_back(r);
                green.push_back(g);
                blue.push_back(b);
            }
            prev_x = mouse_x / scale;
            prev_y = mouse_y / scale;
        }
        draw(pos_x, pos_y, red, green, blue, scales);
        update_color();
        control(pos_x, pos_y, scales);
        SDL_RenderPresent(renderer);
    }
    return 1;
}
