#pragma once
#ifndef ELEMENT_H_INCLUDED
#define ELEMENT_H_INCLUDED
#include "GAME.h"

class Element{
public:
    string tag;
    int x_pos, y_pos;
    int x_size, y_size;
    SDL_Texture* tex;
    Element(SDL_Texture* texture, int x_pos, int y_pos, int x_size, int y_size, string tag);
};

#endif // ELEMENT_H_INCLUDED
