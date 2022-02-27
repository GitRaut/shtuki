#include "mini_paint.h"

HANDLE handlem = GetStdHandle(STD_OUTPUT_HANDLE);

int main()
{
    string way;
    print("Enter the way to file:", 100, "Y");
    cout << endl;
    SetConsoleTextAttribute(handlem, 15);
    getline(cin, way);
    system("cls");
    controller(way);
    SetConsoleTextAttribute(handlem, 15);
    return 0;
}
