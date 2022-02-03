#include "header.h"

HANDLE handlem = GetStdHandle(STD_OUTPUT_HANDLE);

bool check(vector <int> a){
    int count = a.size();
    int col = 0;
    if(count == 1 or count == 0){
        return true;
    }
    for(int i = 1; i < count; i++){
        if(a[i] > a[i - 1]){
            col++;
        }
    }
    if(col == count - 1){
        return true;
    }
    return false;
}

void sortik(vector <int> &a, vector <int> &b, int start_count, string &result, vector <string> &col){
    int max_len = max_len_num(a);
    while(!(check(a)) and a.size() != start_count){
        int count = a.size(), min = min_num(a), pos = find_min(a, min);
        if(pos <= count / 2){
            for(int i = 0; i < pos; i++){
                result += " ra";
                col.push_back("ra");
                ra(a);
                //print_action(a, b, "ra", max_len);
            }
        }
        else{
            for(int i = 0; i < count - pos; i++){
                result += " rra";
                col.push_back("rra");
                rra(a);
                //print_action(a, b, "rra", max_len);
            }
        }
        if(!(check(a)) and a.size() != start_count){
            result += " pb";
            col.push_back("pb");
            pb(a, b);
            //print_action(a, b, "pb", max_len);
        }
    }
    int count_b = b.size();
    for(int i = 0; i < count_b; i++){
        result += " pa";
        col.push_back("pa");
        pa(a, b);
        //print_action(a, b, "pa", max_len);
    }
}

void print_action(const vector <int> &a, const vector<int> &b, string command, int max_len_num){
    int count_a = a.size(), count_b = b.size();
    int max_size = max(count_a, count_b), len, len2;
    SetConsoleTextAttribute(handlem, 10);
    cout << command << ":" << endl;
    SetConsoleTextAttribute(handlem, 15);
    string space = spaces(max_len_num / 2, " "), point, point2;
    cout << space << "a" << space << "  " << space << "b" << endl;
    space = spaces(max_len_num, "-");
    SetConsoleTextAttribute(handlem, 10);
    cout << space << "  " << space << endl;
    SetConsoleTextAttribute(handlem, 15);
    for(int i = 0; i < max_size; i++){
        if(i > count_a - 1)
            point = " ";
        else
            point = itc_ToString(a[i]);

        if(i > count_b - 1)
            point2 = " ";
        else
            point2 = itc_ToString(b[i]);

        len = itc_len(point);
        space = spaces(max_len_num - len, " ");
        cout << point << space << "  " << point2 << endl;
    }
    cout << endl;
}

int main()
{
    print_color_text("Welcome To Sortic:");
    vector <int> a;
    vector <int> b;
    int start_count = a.size();
    string enter;
    vector <string> col;
    string result;
    string vvodi="";
    SetConsoleTextAttribute(handlem, 11);
    getline(cin,vvodi);
    if(vvodi == "/file"){
        vvodi = story();
        result = vvodi + " !";
        cout << vvodi;
    }
    result = vvodi;
    vvod_str(a,b,vvodi);
    //print(a);
    sortik(a, b, start_count, result, col);
    cout << endl;
    SetConsoleTextAttribute(handlem, 10);
    print(a);
    result += " *";
    cout << endl;
    cout << "Count of commands: " << col.size();
    reader(result);
    cout << endl;
    print_color_text("Data saved!");
}
