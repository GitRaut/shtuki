#include "header.h"

void texture_from_image(SDL_Renderer* renderer, SDL_Texture* &texture, string way){
    SDL_Surface* image;
    const char* file = way.data();
    image = IMG_Load(file);
    if(!image){
        cout << "Error! Can't load image";
    }
    texture = SDL_CreateTextureFromSurface(renderer, image);
    SDL_FreeSurface(image);
}
