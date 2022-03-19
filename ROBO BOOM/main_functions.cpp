#include "GAME.h"

void kill(SDL_Window* window, SDL_Renderer* renderer) {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	window = NULL;
	renderer = NULL;
	SDL_Quit();
}

void texture_from_image(SDL_Renderer* renderer, SDL_Texture* &texture, SDL_Surface* &image, string way){
    const char* file = way.data();
    image = IMG_Load(file);
    if(!image){
        cout << "Error! Can't load image";
    }
    texture = SDL_CreateTextureFromSurface(renderer, image);
    SDL_FreeSurface(image);
}

double convert_x_to_screen(double x){
    double screen_x = x - (player.x_pos - (win_w / 2));
    return screen_x;
}

double convert_y_to_screen(double y){
    double screen_y = y - (player.y_pos - (win_h / 2));
    return screen_y;
}

bool is_collision(double x, double y){
    int chunk_x, chunk_y;
    bool res = false;
    chunk_x = (x / tile_size);
    chunk_y = (y / tile_size);

    if (chunk_x<0) return false;
    if (chunk_x>=map_chunk_w) return false;
    if (chunk_y<0) return false;
    if (chunk_y>=map_chunk_h) return false;

    //cout << chunk_x << "|" << chunk_y << endl;
    if(scene.colis_map[chunk_y][chunk_x] == '1'){
        res = true;
    }
    return res;
}
bool is_collision_pl(double x, double y,int x_size,int y_size){
    double chunk_x, chunk_y;
    bool res = false;
    chunk_x = ((x-x_size/2) / tile_size);
    chunk_y = ((y-y_size/2) / tile_size)+1-0.1;
    //cout << chunk_x << "|" << chunk_y << endl;
    for (int i =0;i<x_size/tile_size+1;i++) {
        for (int j =0;j<y_size/tile_size+1;j++) {
           if(scene.colis_map[chunk_y+j][chunk_x+i] == '1'){
            return true;
           }
        }
    }

    //if(scene.colis_map[chunk_y][chunk_x] == '1'){
      //  res = true;
    //}
    return res;
}
bool is_collision_chunk(double x, double y){
    int chunk_x, chunk_y;
    bool res = false;
    chunk_x = x;//roundf(x / tile_size);
    chunk_y = y;//roundf(y / tile_size);
    //cout << chunk_x << "|" << chunk_y << endl;
    if(scene.colis_map[chunk_y][chunk_x] == '1'){
        res = true;
    }
    return res;
}
bool is_visible(double x0,double y0, double x1,double y1)
{
    //x0=x0/tile_size;
    //x1=x1/tile_size;
    //y0=y0/tile_size;
    //y1=y1/tile_size;

    if (x1<x0) {
        swap(x0,x1);
        swap(y0,y1);
    }

    if (x1 != x0) {
    for (int i=x0;i<x1;i++) {
        double y = y0+(y1-y0)/(x1-x0)*(i-x0);
        if (is_collision(i,y)==true ) {return false;}


    }
    }

    if (y1<y0) {
        swap(x0,x1);
        swap(y0,y1);
    }


    if (y1 != y0) {
    for (int i=y0;i<y1;i++) {
        double x = x0+(x1-x0)/(y1-y0)*(i-y0);
        if (is_collision(x,i)==true ) {return false;}


    }
    }
/*
    int deltax = abs(x1 - x0);
     int deltay = abs(y1 - y0);
     int error = 0;
     int deltaerr = (deltay + 1);
     int y = y0;
     int diry = y1 - y0;
     if( diry > 0)
         diry = 1;
     if (diry < 0)
         diry = -1;
     if(x1<x0)
     {
         for(int i=x1;i<x0;i++)
         {
            if (is_collision(i,y)==true || is_collision(i+10,y)==true || is_collision(i-10,y)==true || is_collision(i,y+10)==true || is_collision(i,y-10)==true) {return false;}
            error = error +deltaerr;
            if(error>=(deltax+1))
            {
                y=y-diry;
                error=error -(deltax+1);
            }
         }
     }else
     {
        for(int i=x0;i<x1;i++)
        {

            if (is_collision(i,y)==true || is_collision(i+10,y)==true || is_collision(i-10,y)==true || is_collision(i,y+10)==true || is_collision(i,y-10)==true) {return false;}
            error = error +deltaerr;
            if(error>=(deltax+1))
            {
                y=y+diry;
                error=error -(deltax+1);
            }
        }
     }
     */
     return true;
}

bool is_selected(int x, int y, int x_size, int y_size){
    int x_mouse, y_mouse;
    int xl = x, xr = x + x_size;
    int yl = y, yr = y + y_size;
    SDL_GetMouseState(&x_mouse, &y_mouse);
    if(x_mouse >= xl && x_mouse <= xr && y_mouse >= yl && y_mouse <= yr){
        return true;
    }
    return false;
}

void render_texture(SDL_Renderer* renderer, SDL_Texture* tex, int x, int y, int w, int h){
    SDL_Rect rect = {x, y, w, h};
    SDL_RenderCopy(renderer, tex, NULL, &rect);
}
