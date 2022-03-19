#pragma once
#ifndef GALLERY_H_INCLUDED
#define GALLERY_H_INCLUDED
#include "GAME.h"

class Gallery{
private:
    vector <Element> elements;
    Button r_arrow;
    Button l_arrow;
    int el = 0;
public:
    Gallery(Button r, Button l);
    Gallery();
    void add_element(Element el);
    void gallery_update(SDL_Renderer* renderer);
};

#endif // GALLERY_H_INCLUDED
