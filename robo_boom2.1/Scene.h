#pragma once
#ifndef SCENE_H_INCLUDED
#define SCENE_H_INCLUDED
#include "GAME.h"

using std::vector;
using std::string;

class Scene{
public:
    Scene();
    Scene(SDL_Texture* tex);

    int x_size, y_size;
    vector <vector<char>> colis_map;
    void set_colis_map(string way);
    void update_scene(SDL_Renderer* renderer);

private:
    SDL_Texture* level_map;
};

#endif // SCENE_H_INCLUDED
