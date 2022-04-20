#include "header.h"

int cz_timer = 80;
int timer = 80;

void control(vector <int> &pos_x, vector <int> &pos_y, vector <int> &scales){
    cz_timer--;
    timer--;
    if(GetAsyncKeyState(VK_CONTROL) && GetAsyncKeyState('Z') && pos_x.size() > 0 && cz_timer <= 0){
        pos_x.pop_back();
        pos_y.pop_back();
        scales.pop_back();
        cz_timer = 80;
    }
    if(GetAsyncKeyState(VK_UP) && timer <= 0){
        scale += 10;
        timer = 80;
    }
    if(GetAsyncKeyState(VK_DOWN) && timer <= 0 && scale >= 20){
        scale -= 10;
        timer = 80;
    }
}

void update_color(string color){
    if(color == "R"){
         r = 255;
         g = 0;
         b = 0;
    }
    if(color == "G"){
         r = 0;
         g = 255;
         b = 0;
    }
    if(color == "B"){
         r = 0;
         g = 0;
         b = 255;
    }
    if(color == "O"){
         r = 255;
         g = 125;
         b = 0;
    }
    if(color == "L"){
         r = 18;
         g = 18;
         b = 18;
    }
}
