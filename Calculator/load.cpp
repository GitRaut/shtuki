#include "sup_pup.h"

HANDLE handlel = GetStdHandle(STD_OUTPUT_HANDLE);

void story(){
    ifstream inout("D:\\Code\\calculator\\History.txt", ios::in);
    string str;
    int i = 1;
    if (inout.is_open())
    {
        while ( getline (inout,str) )
        {
            str = str + "\n";
            print(str);
        }
    }
    inout.close();
}

void reader(string ans, string res){
    ofstream out("D:\\Code\\calculator\\History.txt", ios::app);
    if (out.is_open())
    {
        out << ans << res << endl;
    }
    out.close();
}
<<<<<<< HEAD

void error_null(){
    SetConsoleTextAttribute(handlel, 12);
    cout << endl << "Error! You can't divide by zero!" << endl;
    cout << "Try again." << endl << endl;
    SetConsoleTextAttribute(handlel, 15);
}

string itc_ToString(int num){
    string res = "", result = "";
    int point;
    if(num == 0){
        return "0";
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

string check_del(string first, string second){
    if(second == "0" or second == "-0" or second == "+0"){
        cout << endl;
        error_null();
        return "";
    }
    else if(first == "0" or first == "-0" or first == "+0"){
        return "0";
    }
    else if(second == "1"){
        return first;
    }
    return del(first, second);
}
=======
>>>>>>> bad00f03d28d56bb686bb69422844c6ef3d3f362
