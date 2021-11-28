#include "sup_pup.h"

HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

string answer(string first, string second, string znak){
    string ans;
    SetConsoleTextAttribute(handle, 6);
    ans = first + " " + znak + " " + second + " = ";
    return ans;
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
    else if(com == "/mus"){
        music_menu();
    }
    else if(com == "/story"){
        story();
    }
    else if(com != "/help" and com != "/menu" and com != "/start" and com != "/inf" and com != "/mus1" and com != "/mus2" and com != "/mus3" and com!= "/mus4" and com != "/story"){
        error();
    }
    else{
        change_music(com);
    }
}
