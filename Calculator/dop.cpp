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
    mciSendString(TEXT("play clava.wav"), NULL, 0, NULL);
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
    }
    mciSendString(TEXT("stop clava.wav"), NULL, 0, NULL);
    cout << endl;
}

void reader(string ans, string res){
    ofstream out("D:\\Code\\calculator\\History.txt", ios::app);
    if (out.is_open())
    {
        out << ans << res << endl;
        out << "-" << endl << endl;
    }
    out.close();
}

string check_otv(string result){
    string otv;
    if(result[0] == '-' and result[1] == '-'){
        SetConsoleTextAttribute(handlep, 6);
        otv = itc_slice_str(result, 2, itc_len(result) - 1);
        return otv;
    } else{
        SetConsoleTextAttribute(handlep, 6);
        otv = result;
        return otv;
    }
    return "0";
}
