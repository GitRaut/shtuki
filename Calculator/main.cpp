#include "sup_pup.h"

HANDLE handlem = GetStdHandle(STD_OUTPUT_HANDLE);

void main2(){

}
int main()
{
    string command = "", first_num = "", second_num = "", znak = "", result;//commands for console, numbers, operator(+, - , *), result of calculating
    int col;                    //count of iterations in while
    menu();                     //function for printing main menu
    bool mus = PlaySound(TEXT("music.wav"), NULL, SND_ASYNC);
    if(mus == 0){
        PlaySound(TEXT("music.wav"), NULL, SND_ASYNC);
    }
    while(command != "/finish"){//finish stops the program
        check_col(col);
        SetConsoleTextAttribute(handlem, 14);
        cin >> command;        //command reader
        SetConsoleTextAttribute(handlem, 15);
        system("cls");         //clean the console
        check_command(command);
        if(command == "/start"){
            while(znak != "+" and znak != "-" and znak != "*"){
                cout << "What do you want to do with numbers?: (+, -, *)" << endl;
                SetConsoleTextAttribute(handlem, 14);
                cin >> znak;
                SetConsoleTextAttribute(handlem, 15);
                check_value(znak);
            }
            cout << endl << "Enter the first number:" << endl;
            SetConsoleTextAttribute(handlem, 14);
            cin >> first_num;
            SetConsoleTextAttribute(handlem, 15);
            cout << endl << "Enter the second number:" << endl;
            SetConsoleTextAttribute(handlem, 14);
            cin >> second_num;
            SetConsoleTextAttribute(handlem, 15);
            answer(first_num, second_num, znak);//functions for printing answer
            result = result_str(first_num, second_num, znak);
            if(result[0] == '-' and result[1] == '-'){
                cout << itc_slice_str(result, 2, itc_len(result) - 1) << endl << endl;
            } else{
                cout << result << endl << endl;
            }
            SetConsoleTextAttribute(handlem, 15);
        }
        col = 1;
        znak = "";
    }
}
