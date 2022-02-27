#include "mini_paint.h"

void print(string str, int time, string color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    for(int i=0;i<str.size();i++)
    {
        if(str[i]=='*' || str[i]=='+' || str[i]=='/' || str[i]=='-')
        {
            SetConsoleTextAttribute(hConsole, 11);
            cout<<str[i];
           //Sleep(time/9);
        }else{
            if(color=="R")
            {
                SetConsoleTextAttribute(hConsole, 12);
            }else if(color=="G")
            {
                SetConsoleTextAttribute(hConsole, 10);

            }else if(color=="Y")
            {
                SetConsoleTextAttribute(hConsole, 6);

            }
            cout << str[i];
        }
    }
}

int len(string str){
    int len = 0;
    for(int i = 0; str[i] != '\0'; i++){
        len++;
    }
    return len;
}

string get_ext(string way){
    int way_len = len(way);
    int pos;
    string ext = "";
    for(int i = 0; i < way_len; i++){
        if(way[i - 1] == '.'){
            pos = i;
        }
    }
    for(int i = pos; i < way_len; i++){
        ext += way[i];
    }
    return ext;
}

void print_vec(vector <string> vec){
    int count = vec.size();
    for(int i = 0; i < count; i++){
        cout << vec[i] << "*" << endl;
    }
}

void print_vec_int(vector <int> vec){
    int count = vec.size();
    for(int i = 0; i < count; i++){
        cout << vec[i] << endl;
    }
}

string itc_slice_str(string str, int start, int end){
    int lenn = len(str);
    string result = "";
    if((end > lenn) and (start < lenn)){
        for(int i = start; i < lenn; i++){
            result = result + str[i];
        }
        return result;
    }
    if(start > end){
        return str;
    }
    for(int i = start; i <= end; i++){
        result = result + str[i];
    }
    return result;
}
