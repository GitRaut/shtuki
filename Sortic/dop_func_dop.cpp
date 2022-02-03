#include "header.h"

HANDLE handlep = GetStdHandle(STD_OUTPUT_HANDLE);

int max_len_num(vector <int> a){
    int count_a = a.size();
    string point;
    int len;
    int result = 0;
    for(int i = 0; i < count_a; i++){
        point = itc_ToString(a[i]);
        len = itc_len(point);
        if(len > result){
            result = len;
        }
    }
    return result;
}

string itc_ToString(int num){
    string res = "", result = "";
    int point;
    if(num == 0){
        return "0";
    }
    if(num < 0){
        result += "-";
        num = num * -1;
    }
    while(num > 0){
        point = num % 10;
        res += '0' + point;
        num = num / 10;
    }
    for(int i = itc_len(res) - 1; i >= 0; i--){
        result += res[i];
    }
    return result;
}

string spaces(int max_count, string sym){
    string result = "";
    for(int i = 0; i < max_count; i++){
        result += sym;
    }
    return result;
}

void print_color_text(string print){
    mciSendString(TEXT("play clava.wav"), NULL, 0, NULL);
    for(int i = 0; i < itc_len(print); i++){
        if(print[i] == '*'){
            SetConsoleTextAttribute(handlep, 3);
            cout << print[i];
        }
        else if((print[i] >= 'A' and print[i] <= 'Z') or (print[i] >= 'a' and print[i] <= 'z')){
            SetConsoleTextAttribute(handlep, 6);
            cout << print[i];
        }
        else{
            SetConsoleTextAttribute(handlep, 6);
            cout << print[i];
        }
        SetConsoleTextAttribute(handlep, 15);
        if(i % 10 == 0){
            Sleep(1);
        }
        else if((print[i] >= 'A' and print[i] <= 'Z') or (print[i] >= 'a' and print[i] <= 'z')){
            Sleep(1);
        }
    }
    mciSendString(TEXT("stop clava.wav"), NULL, 0, NULL);
    cout << endl;
}
