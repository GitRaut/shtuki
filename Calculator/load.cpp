#include "sup_pup.h"

void story(){
    ifstream inout("D:\\Code\\calculator\\History.txt", ios::in);
    string str;
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

void check_number_res1(string num){
    while(!(check_numbers(num))){
        cout << endl << "Enter the first number:" << endl;
        SetConsoleTextAttribute(handlem, 6);
        cin >> first_num;
        SetConsoleTextAttribute(handlem, 15);
        if(!(check_numbers(num))){
            error();
        }
    }
}

void check_number_res2(string num){
    while(!(check_numbers(num))){
        cout << endl << "Enter the second number:" << endl;
        SetConsoleTextAttribute(handlem, 6);
        cin >> second_num;
        SetConsoleTextAttribute(handlem, 15);
        if(!(check_numbers(num))){
            error();
        }
    }
}
