#include "sup_pup.h"

HANDLE handlep = GetStdHandle(STD_OUTPUT_HANDLE);

string count_of_nul(long long iter){
    string result = "";
    for(long long i = 0; i < iter; i++){
        result += "0";
    }
    return result;
}

void check_value(string znak){
    if(znak != "+" and znak != "-" and znak != "*"){
        error();
    }
}

void print(string print){
    for(int i = 0; i < itc_len(print); i++){
        if(print[i] == '*'){
            SetConsoleTextAttribute(handlep, 3);
            cout << print[i];
        }
        else if((print[i] >= 'A' and print[i] <= 'Z') or (print[i] >= 'a' and print[i] <= 'z')){
            SetConsoleTextAttribute(handlep, 15);
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
        else if(print[i] == ' ' and ((print[i - 1] >= 'A' and print[i - 1] <= 'Z') or (print[i - 1] >= 'a - 1' and print[i] <= 'z - 1'))){
            Sleep(2);
        }
    }
    cout << endl;
}
