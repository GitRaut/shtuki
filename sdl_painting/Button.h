#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED
#include "header.h"

class Button{
private:
    SDL_Texture* on;
    SDL_Texture* off;
    int x_pos, y_pos;
    int x_size, y_size;
    bool is_selected();
public:
    bool selected;
    Button();
    Button(int x, int y, int w, int h, SDL_Texture* active, SDL_Texture* unactive);
    bool click();
    void update(SDL_Renderer* renderer);
};


#endif // BUTTON_H_INCLUDED
