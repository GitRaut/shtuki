#include "header.h"

int pixel_size = 10;
SDL_Window* win;
SDL_Renderer* renderer;
SDL_Texture* bord;

void render_window(){//render window with screen size options
    SDL_DisplayMode DM;
    SDL_GetDesktopDisplayMode(0, &DM);
    int win_w = DM.w;
    int win_h = DM.h - 20;
    win = SDL_CreateWindow("GAME", 0, 20, win_w, win_h, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer( win, -1, SDL_RENDERER_ACCELERATED);
}

void update_brush(Brush &brush, Image img, int x_palette, int y_palette, int palette_scale){
    brush.timer--;
    if(GetAsyncKeyState(VK_RBUTTON))
        brush.change_color(renderer, img, x_palette, y_palette, palette_scale);
    if(GetAsyncKeyState(VK_UP) || (GetAsyncKeyState(VK_DOWN)))
        brush.change_size(1);

}

int main(int argc, char** args)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    render_window();
    SDL_Event event;
    SDL_Texture* color_ramp;
    SDL_Texture* panel, *ins_panel;
    texture_from_image(renderer, color_ramp, "color_ramp.png");
    texture_from_image(renderer, panel, "panel.png");
    texture_from_image(renderer, ins_panel, "panel_instr.png");
    bord = panel;

    Image img;
    img.loadFromFile("color_ramp.png");

    Color color(255, 255, 255, 255);
    Canvas canvas(500, 62, 1300, 930, color);

    Brush brush(color);

    bool quit = false;
    int brush_size = 1, clear_size = 1;
    while(!quit){
        SDL_SetRenderDrawColor(renderer, 19, 23, 28, 18);
        SDL_RenderClear(renderer);
        SDL_PollEvent(&event);
        switch (event.type){
        case SDL_QUIT:
            quit = true;
            break;
        }
        render_texture(renderer, ins_panel, 64, 46, 316, 632);
        render_texture(renderer, panel, 64, 700, 316, 316);
        render_texture(renderer, color_ramp, 92, 728, 260, 260);

        update_brush(brush, img, 92, 728, 260);
        canvas.update(renderer, brush);
        SDL_RenderPresent(renderer);
    }
    return 0;
}
