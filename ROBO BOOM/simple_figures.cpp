#include "GAME.h"

int abs(int num){
    if(num < 0){
        num *= -1;
    }
    return num;
}

void sswap(int &fir, int &sec){
    int point = fir;
    fir = sec;
    sec = point;
}

int max(int first, int sec){
    if(first > sec){
        return first;
    }
    else {
        return sec;
    }
}

void horizontal_line(SDL_Renderer *renderer, int x, int y, int size_l, int color_r, int color_g, int color_b, int a){
    SDL_SetRenderDrawColor(renderer, color_r, color_g, color_b, a);
    if (size_l < 0){
        x += size_l;
        if(x < 0){
            x = 0;
        }
        size_l *= -1;
    }
    for(int i = 0; i < size_l; i++){
        SDL_RenderDrawPoint(renderer, x + i, y);
    }
}

void vertical_line(SDL_Renderer *renderer, int x, int y, int size_l, int color_r, int color_g, int color_b, int color_a){
    SDL_SetRenderDrawColor(renderer, color_r, color_g, color_b, color_a);
    if (size_l < 0){
        y += size_l;
        if(y < 0){
            y = 0;
        }
        size_l *= -1;
    }
    for(int i = 0; i < size_l; i++){
        SDL_RenderDrawPoint(renderer, x, y + i);
    }
}
void square(SDL_Renderer *renderer, int x, int y, int x_len, int y_len, int r, int g, int b, int a, bool fil){
    if(fil){
        if (y_len < 0){
            y += y_len;
            if(y < 0){
                y = 0;
            }
            y_len *= -1;
        }
        if (x_len < 0){
            x += x_len;
            if(x < 0){
                x = 0;
            }
            x_len *= -1;
        }
        for(int i = 0; i < x_len; i++){
            vertical_line(renderer, x, y, y_len, r, g, b, a);
            x++;
        }
    }
    else{
        vertical_line(renderer, x, y, y_len, r, g, b, a);
        horizontal_line(renderer, x, y, x_len, r, g, b, a);
        vertical_line(renderer, x + x_len, y, y_len, r, g, b, a);
        horizontal_line(renderer, x, y + y_len, x_len, r, g, b, a);
    }
}

void line(SDL_Renderer *renderer, int x1, int y1, int x2, int y2)
{
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    int dx;
    int dy;

    if(x2 - x1 >= 0)dx = 1;
    else dx = -1;
    if(y2 - y1 >= 0)dy = 1;
    else dy = -1;

    int lengthX = abs(x2 - x1);
    int lengthY = abs(y2 - y1);
    int length = max(lengthX, lengthY);

    if (length == 0)SDL_RenderDrawPoint(renderer, x1, y1);

    if (lengthY <= lengthX)
    {
    // Начальные значения
        int x = x1;
        int y = y1;
        int d = -lengthX;
        // Основной цикл
        length++;
        while(length--)
        {
            SDL_RenderDrawPoint(renderer, x, y);
            x += dx;
            d += 2 * lengthY;
            if (d > 0) {
                d -= 2 * lengthX;
                y += dy;
            }
        }
      }
      else
      {
        // Начальные значения
        int x = x1;
        int y = y1;
        int d = - lengthY;
        // Основной цикл
        length++;
        while(length--)
        {
            SDL_RenderDrawPoint(renderer, x, y);
            y += dy;
            d += 2 * lengthX;
            if (d > 0) {
                d -= 2 * lengthY;
                x += dx;
            }
        }
      }
}
