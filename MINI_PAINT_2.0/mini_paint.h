#ifndef MINI_PAINT_H_INCLUDED
#define MINI_PAINT_H_INCLUDED

#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>
#include <sstream>

using namespace std;

void controller(string way);
void render(vector <string> com, bool is_save);
void reader(string way, vector <string> &res);
void print(string str, int time, string color);
void print_vec(vector <string> vec);
void print_vec_int(vector <int> vec);
void change_color(string str);
void change_sym(char &sym, char sym_back, int height, string iter);

bool check_way(string way);
bool ch_check(string str);
bool set_colors(string str, string &color);
bool value_check(int value, int min, int max);
bool set_values(string str, vector <int> &args);
bool fon_check(string str, vector <int> &args);

string is_open(string way);
string count_of_arg(string way);
string valid_name(string way);
string check_ext(string way);
string get_ext(string way);
string itc_slice_str(string str, int start, int end);

int len(string str);
int slice_point(string way);

vector <string> values(string str);

void rectangle(int xrec,int yrec,int width, int height, char kontur, int resolution_height,int resolution_width, char fil, bool fil_bool);
void line(int x1, int y1, int x2, int y2,char kontur,int resolution_width,int resolution_height);
void circle(int X1, int Y1, int R, char kontur, char fil,bool fil_bool,int resolution_width,int resolution_height);
void fon(char fon, int resolution_width,int resolution_height);
void gotoxy(int x,int y);

void save_to_file(vector<vector<char>>&coordinats);
void rectangle_save(int xrec,int yrec,int width, int height, char kontur, int resolution_height,int resolution_width, char fil, bool fil_bool,vector<vector<char>>&coordinats);
void circle_save(int X1, int Y1, int R, char kontur, char fil,bool fil_bool,int resolution_width,int resolution_height,vector<vector<char>>&coordinats);
void line_save(int x1, int y1, int x2, int y2,char kontur,int resolution_width,int resolution_height,vector<vector<char>>&coordinats);
void fon_save(char fon_fil, int resolution_width,int resolution_height,vector<vector<char>>&coordinats);


#endif // MINI_PAINT_H_INCLUDED
