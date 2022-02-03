#include "header.h"

HANDLE handlet = GetStdHandle(STD_OUTPUT_HANDLE);


void print(const vector <int> &vec){
    int count = vec.size();
    if(count > 0){
        for(int i = 0; i < count; i++){
            cout << vec[i] << " ";
        }
    }
}

int itc_len(string str){
    int len = 0;
    for(int i = 0; str[i] != '\0'; i++){
        len++;
    }
    return len;
}

int to_int(string str){
    int num = 0, len = itc_len(str);
    for(int i = 0; i < len; i++){
        if(str[i] >= '0' and str[i] <= '9'){
            num = num * 10 + (str[i] - '0');
        }
    }
    if(str[0] == '-'){
        num = num * -1;
    }
    return num;
}

int find_min(vector <int> a, int min){
    int count = a.size();
    for(int i = 0; i < count; i++){
        if(a[i] == min){
            return i;
        }
    }
    return 0;
}

void print_error()
{
    SetConsoleTextAttribute(handlet, 12);
    cout << "Incorect input. Try agane or go to https://docs.google.com/document/d/1gLua8u2oTlD001AJ5yudl1x47V2wFeft/edit   :/";
    cout << endl;
}
