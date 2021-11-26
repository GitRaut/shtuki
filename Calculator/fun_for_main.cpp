#include "sup_pup.h"

HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

void answer(string first, string second, string znak){
    cout << endl << "Answer:" << endl;
    SetConsoleTextAttribute(handle, 6);
    cout << first << " " << znak << " " << second << " = ";
}

void error(){
    SetConsoleTextAttribute(handle, 12);
    cout << endl << "Error! Not the correct value!" << endl;
    cout << "Try again." << endl << endl;
    SetConsoleTextAttribute(handle, 15);
}

void check_col( int col){
    if(col < 1){
        cout << "Enter the command:" << endl;
    }
    else {
        cout << "Enter the command:";
        SetConsoleTextAttribute(handle, 10);
        cout << " \"-/help\" (to find out what the calculator can do);" << endl;
        SetConsoleTextAttribute(handle, 15);
    }
}

void check_command(string com){
    if(com == "/help"){
        help();             //function for printing "help" menu with list of commands
    }
    else if(com == "/menu"){
        menu_part1();             //function for printing main menu
        menu_part2();
    }
    else if(com == "/inf"){
        information();      //function for printing inf about calculator
    }
    else if(com == "/start"){
        main2();
    }
    else if(com != "/help" and com != "/menu" and com != "/start" and com != "/inf"){
        error();
    }
}
