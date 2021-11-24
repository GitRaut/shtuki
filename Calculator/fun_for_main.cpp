#include "sup_pup.h"

void answer(string first, string second, string znak){
    cout << endl << "Answer:" << endl;
    cout << first << " " << znak << " " << second << " = ";
}

void error(){
    cout << endl << "Error! Not the correct value!" << endl;
    cout << "Try again." << endl << endl;
}

void check_col( int col){
    if(col < 1){
        cout << "Enter the command:" << endl;
    }
    else {
        cout << "Enter the command:" << " \"-/help\" (to find out what the calculator can do);" << endl;
    }
}

void check_command(string com){
    if(com == "/help"){
        help();             //function for printing "help" menu with list of commands
    }
    else if(com == "/menu"){
        menu();             //function for printing main menu
    }
    else if(com == "/inf"){
        information();      //function for printing inf about calculator
    }
    else if(com != "/help" and com != "/menu" and com != "/start" and com != "/inf"){
        error();
    }
}
