#ifndef SUP_PUP_H_INCLUDED
#define SUP_PUP_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

void menu();
void help();
void information();

void error();
void check_col( int col);
void check_command(string com);
void answer(string first, string second, string znak);

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
string sum(string first, string second);
string max_str(string first, string second);
string min_str(string first, string second);
string subtraction(string first, string second);
string itc_slice_str(string str, int start, int end);
string result_str(string first, string second, string znak);

#endif // SUP_PUP_H_INCLUDED
