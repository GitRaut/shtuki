#include "sup_pup.h"

HANDLE handlem = GetStdHandle(STD_OUTPUT_HANDLE);

void main3(string first_num, string second_num, string znak){
    string result, flag, ans;
    SetConsoleTextAttribute(handlem, 15);
    cout << endl << "Answer:" << endl;
    cout << answer(first_num, second_num, znak);                        //functions for printing answer
    result = result_str(first_num, second_num, znak);
    cout << check_otv(result) << endl << endl;                          //function for printing result
    ans = answer(first_num, second_num, znak);
    flag = check_otv(result);
    reader(ans, flag);
    SetConsoleTextAttribute(handlem, 15);
}

void main2(){
    string first_num = "a", second_num = "a", znak = "", result, flag, ans;//commands for console, numbers, operator(+, - , *), result of calculating                                                             //count of iterations in while
    while(znak != "+" and znak != "-" and znak != "*" and znak != "/"){
        cout << "What do you want to do with numbers?: (+, -, *, /)" << endl;
        SetConsoleTextAttribute(handlem, 6);
        cin >> znak;
        SetConsoleTextAttribute(handlem, 15);
        check_value(znak);
    }
    while(!(numbol(first_num)) or !(numbol(second_num))){
        cout << endl << "Enter the first number:" << endl;
        SetConsoleTextAttribute(handlem, 6);
        cin >> first_num;
        SetConsoleTextAttribute(handlem, 15);
        cout << endl << "Enter the second number:" << endl;
        SetConsoleTextAttribute(handlem, 6);
        cin >> second_num;
        if(!(numbol(first_num)) or !(numbol(second_num))){
            error();
        }
    }
    main3(first_num, second_num, znak);
    znak = "";
}

int main()
{
    int col = 0;
    string command = "";
    menu_part1();               //function for printing main menu
    menu_part2();
    PlaySound( "music.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP );
    //mciSendString(TEXT("play music.wav"), NULL, 0, NULL);
    while(command != "/finish"){//finish stops the program
        check_col(col);
        SetConsoleTextAttribute(handlem, 6);
        cin >> command;        //command reader
        SetConsoleTextAttribute(handlem, 15);
        system("cls");         //clean the console
        check_command(command);//check cin >> command
        col = 1;
    }
}
