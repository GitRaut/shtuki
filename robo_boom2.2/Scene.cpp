#include "GAME.h"
#include "Scene.h"

Scene::Scene(){}
Scene::Scene(SDL_Texture* tex){
    level_map = tex;
}

void Scene::update_scene(SDL_Renderer* renderer){
    int screen_x, screen_y;
    screen_x = convert_x_to_screen(0);
    screen_y = convert_y_to_screen(0);
    SDL_Rect rect = {screen_x, screen_y, x_size, y_size};
    SDL_RenderCopy(renderer, level_map, NULL, &rect);
}

void Scene::set_colis_map(string way){
    const char* file = way.data();
    for(int y = 0; y < map_chunk_h; y++){
        vector <char> el;
        for(int x = 0; x < map_chunk_w; x++){
            el.push_back('0');
        }
        colis_map.push_back(el);
    }
    ifstream f(file);
    char ch;
    for(int y = 0; y < map_chunk_h; y++){
        for(int x = 0; x < map_chunk_w; x++){
            f >> colis_map[y][x];
        }
    }
}
