#ifndef SUP_PUP_H_INCLUDED
#define SUP_PUP_H_INCLUDED
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <windows.h>
#include <fstream>

using namespace std;

void help();
void main2();
void story();
void music_menu();
void menu_part1();
void menu_part2();
void information();
void print(string print);
void change_music(string com);
bool check_numbers(string num);
void check_number_res1(string num);
void check_number_res2(string num);
void reader(string ans, string res);

void error();
void check_col( int col);
void check_command(string com);
void check_value(string znak);

long long itc_len(string str);
long long itc_ToInt(string str);
long long min_len(string first, string second);
long long max_len(string first, string second);

int isInt(char ch);
int symbol(string str);
int char_to_int(char symbol);
int get_char_int(string str, int index);

string slice(string str);
string reverse_str(string str);
string check_otv(string result);
string count_of_nul(long long iter);
string sum(string first, string second);
string max_str(string first, string second);
string min_str(string first, string second);
string multiply(string first, string second);
string subtraction(string first, string second);
string itc_slice_str(string str, int start, int end);
string answer(string first, string second, string znak);
string result_str(string first, string second, string znak);


#endif // SUP_PUP_H_INCLUDED
