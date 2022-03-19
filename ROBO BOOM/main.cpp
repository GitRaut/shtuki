#include "GAME.h"
#define WINDOW_WIDTH 1000

int win_w;
int win_h;
SDL_Window* win;
SDL_Renderer* renderer;

void render_window(int &win_width, int &win_height){
    SDL_DisplayMode DM;
    SDL_GetDesktopDisplayMode(0, &DM);
    win_width = DM.w;
    win_height = DM.h - 20;

    win = SDL_CreateWindow("GAME", 0, 20, win_w, win_h, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer( win, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(renderer, 32, 24, 43, 255);
}

int main(int argc, char** args) {
    SDL_Init(SDL_INIT_EVERYTHING);
    render_window(win_w, win_h);
    Game(renderer);
    kill(win, renderer);
}
