#include "sup_pup.h"

int char_to_int(char symbol){
    int result = 0;
    result = (result * 10) + (symbol - '0');
    return result;
}

int get_char_int(string str, int index){
    if(index < 0 or index >= itc_len(str)){
        return 0;
    }
    return char_to_int(str[index]);
}

int symbol(string str){
    if(str[0] == '-'){
        return -1;
    }
    else if(str[0] == '+' or (str[0] >= '0' and str[0] <= '9')){
        return 1;
    }
    else if(str[0] == '*'){
        return 10;
    }
    else if(str[0] == '/'){
        return 20;
    }
}

string slice(string str){
    if(str[0] == '-' or str[0] == '+'){
        str = itc_slice_str(str, 1, itc_len(str) - 1);
    }
    return str;
}

int isInt(char ch){
    if(ch >= '0' and ch <= '9'){
        return 1;
    }
    return 0;
}
