#include "sup_pup.h"

int main()
{
    string command = "", first_num = "", second_num = "", znak = "", result;//commands for console, numbers, operator(+, - , *), result of calculating
    int col;                    //count of iterations in while
    menu();                     //function for printing main menu
    while(command != "/finish"){//finish stops the program
        check_col(col);
        cin >> command;         //command reader
        system("cls");          //clean the console
        check_command(command);
        if(command == "/start"){
            cout << "What do you want to do with numbers?: (+, -, *)" << endl;
            cin >> znak;
            cout << endl << "Enter the first number:" << endl;
            cin >> first_num;
            cout << endl << "Enter the second number:" << endl;
            cin >> second_num;
            answer(first_num, second_num, znak);//functions for printing answer
            result = result_str(first_num, second_num, znak);
            if(result[0] == '-' and result[1] == '-'){
                cout << itc_slice_str(result, 2, itc_len(result) - 1) << endl << endl;
            } else{
                cout << result << endl << endl;
            }
            if(znak == "*"){
                cout << endl << "Try Later!" << endl << endl;//Later i will do it!
            }
        }
        col = 1;
    }
}
