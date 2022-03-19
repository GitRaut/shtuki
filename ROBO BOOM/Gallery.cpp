#include "GAME.h"
#include "Gallery.h"

Gallery::Gallery(Button r, Button l){
    r_arrow = r;
    l_arrow = l;
}
Gallery::Gallery(){}
void Gallery::add_element(Element el){
    elements.push_back(el);
}

void Gallery::gallery_update(SDL_Renderer* renderer){
    r_arrow.update(renderer);
    l_arrow.update(renderer);

    if(elements.size() > 0){
        if(r_arrow.click()) el++;
        if(l_arrow.click()) el--;

        if(el < 0)el = elements.size() - 1;
        if(el > elements.size() - 1) el = 0;

        SDL_Rect rect = {elements[el].x_pos, elements[el].y_pos, elements[el].x_size, elements[el].y_size};
        SDL_RenderCopy(renderer, elements[el].tex, NULL, &rect);
    }
}

