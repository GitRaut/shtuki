#include "GAME.h"
#include "element.h"

Element::Element(SDL_Texture* texture, int x, int y, int w, int h, string _tag){
    tex = texture;
    x_pos = x;
    y_pos = y;
    x_size = w;
    y_size = h;
    tag = _tag;
}
