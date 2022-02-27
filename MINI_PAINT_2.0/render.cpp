#include "mini_paint.h"

HANDLE hConsoles = GetStdHandle(STD_OUTPUT_HANDLE);

void render(vector <string> com, bool is_save){
    vector <vector<char>> coordinates;
    string num, color, er = "";
    vector <int> args;
    int count = com.size(), width, height;
    char sym, func, sym_back;
    bool checker = fon_check(com[0], args), checker_1;
    if(checker){
        width = args[0];
        height = args[1];
        sym_back = (char)args[2];
        checker = value_check(width, 1, 300);
        checker_1 = value_check(height, 1, 300);
        if(checker && checker_1){
            fon(sym_back, width, height);
            if(is_save) fon_save(sym_back, width, height, coordinates);
            for(int i = 1; i < com.size(); i++){
                checker = set_values(com[i], args);
                checker_1 = set_colors(com[i], color);
                if(checker && checker_1){
                    num = to_string(i + 1);
                    func = (char)args[0];
                    sym = (char)args[args.size() - 1];
                    change_sym(sym, sym_back, height, num);
                    change_color(color);
                    switch(func){
                        case 'r':
                            if(args[3] > 0 && args[4] > 0){
                                rectangle(args[1], args[2], args[3], args[4], sym, height, width, sym, 0);
                                if(is_save) rectangle_save(args[1], args[2], args[3], args[4], sym, height, width, sym, 0, coordinates);
                            }
                            else{
                                i = com.size();
                                er = "Error! Invalid value! Line#" + num;
                            }
                            break;
                        case 'R':
                            if(args[3] > 0 && args[4] > 0){
                                rectangle(args[1], args[2], args[3], args[4], sym, height, width, sym, 1);
                                if(is_save) rectangle_save(args[1], args[2], args[3], args[4], sym, height, width, sym, 1, coordinates);
                            }
                            else{
                                i = com.size();
                                er = "Error! Invalid value! Line#" + num;
                            }
                            break;
                        case 'c':
                            if(args[3] > 0){
                                circle(args[1], args[2], args[3], sym, sym, 0, width, height);
                                if(is_save) circle_save(args[1], args[2], args[3], sym, sym, 0, width, height, coordinates);
                            }
                            else{
                                i = com.size();
                                er = "Error! Invalid value! Line#" + num;
                            }
                            break;
                        case 'C':
                            if(args[3] > 0){
                                circle(args[1], args[2], args[3], sym, sym, 1, width, height);
                                if(is_save) circle_save(args[1], args[2], args[3], sym, sym, 1, width, height, coordinates);
                            }
                            else{
                                i = com.size();
                                er = "Error! Invalid value! Line#" + num;
                            }
                            break;
                        case 'L':
                            line(args[1] - 1, args[2], args[3] - 1, args[4] - 1, sym, width, height);
                            if(is_save) line_save(args[1], args[2], args[3], args[4] - 1, sym, width, height, coordinates);
                            break;
                    }
                }
                else{
                    er = " ";
                    system("cls");
                    gotoxy(0, 0);
                    checker = set_values(com[i], args);
                    checker_1 = set_colors(com[i], color);
                    i = com.size();
                }
            }
        }
        if(er == ""){
            gotoxy(width, height);
        }
        else{
            if(er != " "){
                system("cls");
            }
            gotoxy(1, 0);
            print(er, 100, "R");
        }
    }
    if(is_save) save_to_file(coordinates);
}

vector <string> values(string str){
    stringstream s(str);
    vector <string> res;
    string value;
    while (s >> value)
        res.push_back(value);
    return res;
}

bool set_values(string str, vector <int> &args){
    vector <string> val = values(str);
    vector <int> res;
    string point = val[0];
    int num, count = 1;
    if(ch_check(point)){
        res.push_back((int)point[0]);
        for(int i = 1; i < val.size() - 2; i++){
            try{
                num = stoi(val[i]);
            }
            catch(std::invalid_argument){
                print("Error! Ivalid value in numbers!", 100, "R");
                return false;
            }
            res.push_back(num);
            count++;
        }
        point = val[count];
        if(ch_check(point)){
            res.push_back((int)point[0]);
        }
        else{
            print("Error! Ivalid value in paint symbol!", 100, "R");
            return false;
        }
        args = res;
        return true;
    }
    print("Error! Invalid value in function symbol!", 100, "R");
    return false;
}

bool ch_check(string str){
    if(len(str) > 1){
        return false;
    }
    return true;
}

bool set_colors(string str, string &color){
    vector <string> val = values(str);
    string res = val[val.size() - 1];
    if(res != "RGB_R" && res != "RGB_G" && res != "RGB_B" && res != "RGB_Y" && res != "RGB_W"){
        print("Error! Invalid value in colors!", 100, "R");
        return false;
    }
    color = res;
    return true;
}

bool fon_check(string str, vector <int> &args){
    vector <string> val = values(str);
    vector <int> res;
    string point = val[val.size() - 1];
    int num;
    if(val.size() > 3){
        print("Error! A lot of arguments for background!", 100, "R");
        return false;
    }
    for(int i = 0; i < val.size() - 1; i++){
        try{
            num = stoi(val[i]);
        }
        catch(std::invalid_argument){
            print("Error! Ivalid value in fon arguments!", 100, "R");
            return false;
        }
        res.push_back(num);
    }
    if(ch_check(point)){
        num = (int)point[0];
        res.push_back(num);
    }
    else{
        print("Error! Invalid value in background symbol!", 100, "R");
        return false;
    }
    args = res;
    return true;
}

void change_color(string str){
    if(str == "RGB_R")
        SetConsoleTextAttribute(hConsoles, 12);
    else if(str == "RGB_G")
        SetConsoleTextAttribute(hConsoles, 10);
    else if(str == "RGB_Y")
        SetConsoleTextAttribute(hConsoles, 6);
    else if(str == "RGB_B")
        SetConsoleTextAttribute(hConsoles, 9);
    else if(str == "RGB_W")
        SetConsoleTextAttribute(hConsoles, 15);
}

void change_sym(char &sym, char sym_back, int height, string iter){
    string predl = "Do you want to change symbol?(line#)" + iter + "(y/n):";
    if(sym == sym_back){
        string otv = "";
        string new_sym;
        gotoxy(0, height + 1);
        print(predl, 100, "Y");
        SetConsoleTextAttribute(hConsoles, 15);
        cin >> otv;
        if(otv == "y"){
            print("Enter new symbol:", 100, "Y");
            cin >> new_sym;
            sym = new_sym[0];
        }
    }
}
