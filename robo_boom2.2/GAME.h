#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

//libs
#include <iostream>
//#include <SDL2/SDL.h>
#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_image.h>
//#include <SDL2/SDL_mixer.h>
#include <windows.h>
#include <mmsystem.h>
#include <fstream>
#include <vector>
#include <cmath>
#include <string>

//classes
#include "Scene.h"
#include "Player.h"
#include "Camera.h"

#include "Prisoner.h"
#include "Helicopter.h"
#include "Gun.h"
#include "Bot_robot.h"
#include "Vzryv.h"
#include "User_Interface.h"
#include "Bullet.h"
#include "Button.h"
#include "Bot_tank.h"
#include "element.h"
#include "Gallery.h"

using namespace std;

extern int tile_size;
extern int win_w;
extern int win_h;
extern Player player;
//extern Prisoner prisoner;
extern int map_chunk_w;
extern int map_chunk_h;
extern Scene scene;

extern SDL_Texture* texture_bullet;
extern SDL_Texture* texture_Bot_robots;
extern SDL_Texture* texture_vzryv;
extern SDL_Texture* player_automat_passive;
extern SDL_Texture* logo_text;

extern SDL_Surface* image_bullet;
extern SDL_Texture* automat_bullet;
extern SDL_Texture* rpg_bullet;
extern SDL_Texture* pistol_bullet;

extern std::vector<Gun_item>Gun_items;
extern std::vector<Bullet>bullets;
extern std::vector<Bot_robot>Bot_robots;
extern std::vector <Vzryv> Vzryvs;
extern bool game, game_music;
extern Mix_Music* musc;

extern int mus_loud;
extern int ef_loud;

void Game(SDL_Renderer* renderer);
void render_window(int &win_width, int &win_height);
void rand_spawn(int count_items, int count_bots);

void kill(SDL_Window* window, SDL_Renderer* renderer);
void render_texture_image(SDL_Renderer* renderer, SDL_Texture* texture, int x, int y, int width, int height, string way);
void texture_from_image(SDL_Renderer* renderer, SDL_Texture* &texture, SDL_Surface* &image, string way);
void render_texture(SDL_Renderer* renderer, SDL_Texture* tex, int x, int y, int w, int h);

double convert_x_to_screen(double x);
double convert_y_to_screen(double y);
bool is_collision(double x, double y);
bool is_visible(double x0,double y0, double x1,double y1);
bool is_collision_pl(double x, double y,int x_size,int y_size);
bool is_collision_chunk(double x, double y);
bool is_selected(int x, int y, int x_size, int y_size);

extern bool l;
extern bool r;
extern bool p;

#endif // GAME_H_INCLUDED
