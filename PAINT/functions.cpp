#include "header.h"

void render_texture(
    SDL_Renderer* renderer,
    SDL_Texture* tex,
    int x, int y,
    int w, int h)
{
    SDL_Rect rect = {x, y, w, h};
    SDL_RenderCopy(renderer, tex, NULL, &rect);
}

void texture_from_image(
    SDL_Renderer* renderer,
    SDL_Texture* &texture,
    string way)
{
    SDL_Surface* image;
    const char* file = way.data();
    image = IMG_Load(file);
    if(!image)
        cout << "Error! Can't load image";
    texture = SDL_CreateTextureFromSurface(renderer, image);
    SDL_FreeSurface(image);
}
