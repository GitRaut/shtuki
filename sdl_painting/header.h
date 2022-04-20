#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>
#include <vector>
#include <windows.h>
#include <SDL.h>
#include <SDL_image.h>

#include "Button.h"

using namespace std;
extern int scale;
extern int r, g, b;
extern SDL_Renderer* renderer;

void draw(vector <int> pos_x, vector <int> pos_y, vector <int> red, vector <int> green, vector <int> blue, vector <int> scales);
void texture_from_image(SDL_Renderer* renderer, SDL_Texture* &texture, string way);
void control(vector <int> &pos_x, vector <int> &pos_y, vector <int> &scales);
void update_color(string color);

#endif // HEADER_H_INCLUDED
