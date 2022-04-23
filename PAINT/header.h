#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include <windows.h>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

#include "Brush.h"
#include "Pixel.h"
#include "Canvas.h"

extern int pixel_size;
extern SDL_Texture* bord;

void render_texture(
    SDL_Renderer* renderer,
    SDL_Texture* tex,
    int x, int y,
    int w, int h);

void texture_from_image(
    SDL_Renderer* renderer,
    SDL_Texture* &texture,
    string way);

#endif // HEADER_H_INCLUDED
