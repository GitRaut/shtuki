#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include <fstream>

using namespace std;

void print(const vector <int> &vec);
int itc_len(string str);
int to_int(string str);
int max_num(vector <int> a);
int min_num(vector <int> a);
int find_min(vector <int> a, int min);
int max(int a, int b);
int min(int a, int b);
string itc_ToString(int num);
int max_len_num(vector <int> a);
void print_action(const vector <int> &a, const vector<int> &b, string command, int max_len_num);
string spaces(int max_count, string sym);
void vvod_str(vector<int> &a,vector<int> &b,string vvod);
void nubmer_string_to_list(string vvod, vector <int> &a);
void print_color_text(string print);
string story();
void reader(string vvod);
void print_error();

void sa(vector <int> &a);
void sb(vector <int> &b);
void ss(vector <int> &a, vector <int> &b);
void pa(vector <int> &a, vector <int> &b);
void pb(vector <int> &a, vector <int> &b);
void ra(vector <int> &a);
void rb(vector <int> &b);
void rr(vector <int> &a, vector<int> &b);
void rra(vector <int> &a);
void rrb(vector <int> &b);
void rrr(vector <int> &a, vector<int> &b);

#endif // HEADER_H_INCLUDED
