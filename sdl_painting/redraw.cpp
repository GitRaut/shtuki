#include "header.h"

void draw(vector <int> pos_x, vector <int> pos_y, vector <int> red, vector <int> green, vector <int> blue, vector <int> scales){
    for(int i = 0; i < pos_x.size(); i++){
        SDL_Rect rect = {
            pos_x[i] * scales[i],
            pos_y[i] * scales[i],
            scales[i], scales[i]};
        SDL_SetRenderDrawColor(renderer, red[i], green[i], blue[i], 255);
        SDL_RenderFillRect(renderer, &rect);
    }
}
