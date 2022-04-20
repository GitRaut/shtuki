#include "header.h"
#define WINDOW_WIDTH 600

int win_w;
int win_h;
int mouse_x = -1;
int mouse_y = -1;
int r = 18;
int g = 18;
int b = 18;
int scale = 10;
SDL_Window* win;
SDL_Renderer* renderer;

void render_window(int &win_width, int &win_height){//render window with screen size options
    SDL_DisplayMode DM;
    SDL_GetDesktopDisplayMode(0, &DM);
    win_width = DM.w;
    win_height = DM.h - 20;
    win = SDL_CreateWindow("GAME", 0, 20, win_w, win_h, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer( win, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(renderer, 18, 18, 18, 255);
}

void load_textures(vector <SDL_Texture*> &mass){
    SDL_Texture* color;
    texture_from_image(renderer, color, "D:\\paint_SDL\\red.png");
    mass.push_back(color);
    texture_from_image(renderer, color, "D:\\paint_SDL\\red_u.png");
    mass.push_back(color);

    texture_from_image(renderer, color, "D:\\paint_SDL\\green.png");
    mass.push_back(color);
    texture_from_image(renderer, color, "D:\\paint_SDL\\green_u.png");
    mass.push_back(color);

    texture_from_image(renderer, color, "D:\\paint_SDL\\blue.png");
    mass.push_back(color);
    texture_from_image(renderer, color, "D:\\paint_SDL\\blue_u.png");
    mass.push_back(color);

    texture_from_image(renderer, color, "D:\\paint_SDL\\orange.png");
    mass.push_back(color);
    texture_from_image(renderer, color, "D:\\paint_SDL\\orange_u.png");
    mass.push_back(color);

    texture_from_image(renderer, color, "D:\\paint_SDL\\lastik_act.png");
    mass.push_back(color);
    texture_from_image(renderer, color, "D:\\paint_SDL\\lastik.png");
    mass.push_back(color);

    texture_from_image(renderer, color, "D:\\paint_SDL\\delete_act.png");
    mass.push_back(color);
    texture_from_image(renderer, color, "D:\\paint_SDL\\delete.png");
    mass.push_back(color);
}

int main(int argc, char** args) {
    SDL_Init(SDL_INIT_EVERYTHING);
    render_window(win_w, win_h);
    SDL_Event event;

    vector <SDL_Texture*> colors;
    load_textures(colors);
    Button red_b(50, 50, 80, 80, colors[0], colors[1]);
    Button green_b(130, 50, 80, 80, colors[2], colors[3]);
    Button blue_b(50, 130, 80, 80, colors[4], colors[5]);
    Button orange_b(130, 130, 80, 80, colors[6], colors[7]);
    Button lastik(60, 220, 60, 80, colors[8], colors[9]);
    Button del(140, 220, 60, 80, colors[10], colors[11]);

    bool quit = false;//check is window quit
    bool is_draw = false;//check mouse button state
    int prev_x = -1, prev_y = -1;//help to check last position and not to add this again

    vector <int> pos_x, pos_y;//vectors with values for x and y position for each element
    vector <int> scales;//vector with scale values for each element
    vector <int> red, green, blue;//vectors with values for colors for each element

    while(!quit){
        SDL_Delay(1);
        SDL_SetRenderDrawColor(renderer, 18, 18, 18, 255);
        SDL_RenderClear(renderer);
        SDL_PollEvent(&event);
        switch (event.type){
        case SDL_QUIT:
            quit = true;
            break;
        }
        is_draw = false;
        if(GetAsyncKeyState(VK_LBUTTON)){
            is_draw = true;
            if(red_b.click())
                update_color("R");//change color
            if(green_b.click())
                update_color("G");//change color
            if(blue_b.click())
                update_color("B");//change color
            if(orange_b.click())
                update_color("O");//change color
            if(lastik.click()){
                update_color("L");//change color
            }
            if(del.click()){
                vector<int>().swap(pos_x);
                vector<int>().swap(pos_y);
                vector<int>().swap(scales);
                vector<int>().swap(red);
                vector<int>().swap(blue);
                vector<int>().swap(green);
            }
        }
        if(is_draw){
            SDL_GetMouseState(&mouse_x, &mouse_y);//get mouse position in our window
            if(mouse_x / scale != prev_x || mouse_y / scale != prev_y){//add new values to vectors
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
        draw(pos_x, pos_y, red, green, blue, scales);//draw all elements which we drew before
        control(pos_x, pos_y, scales);//check keys state and hot keys

        red_b.update(renderer);
        green_b.update(renderer);
        blue_b.update(renderer);
        orange_b.update(renderer);
        lastik.update(renderer);
        del.update(renderer);

        SDL_RenderPresent(renderer);
    }
    return 1;
}
