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
    if(com == "/help" or com == ".ðóäç"){
        help();             //function for printing "help" menu with list of commands
    }
    else if(com == "/menu" or com == ".üóòã"){
        menu_part1();             //function for printing main menu
        menu_part2();
    }
    else if(com == "/inf" or com == ".øòà"){
        information();      //function for printing inf about calculator
    }
    else if(com == "/start" or com == ".ûåôêå"){
        main2();
    }
    else if(com == "/mus" or com == ".üãû"){
        music_menu();
    }
    else if(com == "/story" or com == ".ûåùêí"){
        story();
    }
    else if(com == "/mus1" or com == "/mus2" or com == "/mus3" or com == "/mus4" or com == "HAPPYNEWYEAR"){
        change_music(com);
    }
    else{
        error();
    }
}
