#include "mini_paint.h"

bool check_way(string way){
    string checker, is_save;
    bool res = true;
    checker = count_of_arg(way);
    is_save = count_of_arg(way);
    if(checker != "OK" && is_save != "save"){
        print(checker, 100, "R");
        res = false;
    }
    checker = valid_name(way);
    if(checker != "OK" && is_save != "save"){
        print(checker, 100, "R");
        res = false;
    }
    checker = check_ext(way);
    if(checker != "OK" && is_save != "save"){
        print(checker, 100, "R");
        res = false;
    }
    checker = is_open(way);
    if(checker != "OK" && is_save != "save"){
        print(checker, 100, "R");
        res = false;
    }
    return res;
}

string is_open(string way){
    ifstream file(way);
    if(file){
        return "OK";
    }
    return "Error: Operation file corrupted! \n";
}

string count_of_arg(string way){
    int way_len = len(way), j = 0;
    string save = "";
    for(int i = 0; i < way_len; i++){
        if(way[i] != ' ')
            j ++;
        if(way[i] == ' ')
            j -= 6;
    }
    save = itc_slice_str(way, j + 1, way_len - 1);
    for(int i = 0; i < way_len; i++){
        if(way[i] == ' ' && save != "--save"){
            return "Error: a lot of arguments! \n";
        }
    }
    if(save == "--save"){
        return "save";
    }
    return "OK";
}

string valid_name(string way){
    ifstream file(way);
    if(file.fail()){
        return "Error: name file! \n";
    }
    return "OK";
}

string check_ext(string way){
    string ext = get_ext(way);
    if(ext == "it" || ext == "IT"){
        return "OK";
    }
    else{
        return "Error: Operation file has not correct extension! \n";
    }
    return "OK";
}

bool value_check(int value, int min, int max){
    if(value < min || value > max){
        print("Error! Invalid value!", 100, "R");
        return false;
    }
    return true;
}

int slice_point(string way){
    int way_len = len(way), j = 0;
    string save = "";
    while(way[j] != ' '){
        j++;
    }
    save = itc_slice_str(way, j + 1, way_len - 1);
    if(save == "--save"){
        return j + 1;
    }
    return -1;
}
