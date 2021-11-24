#include "sup_pup.h"

long long itc_ToInt(string str){
    long long num = 0;
    for(int i = 0; i < itc_len(str); i++){
        if(str[i] >= '0' and str[i] <= '9'){
            num = num * 10 + (str[i] - '0');
        }
    }
    return num;
}

string itc_slice_str(string str, int start, int end){
    long long len = itc_len(str);
    string result;
    if((end > len) and (start < len)){
        for(int i = start; i < len; i++){
            result = result + str[i];
        }
        return result;
    }
    if(start > end){
        return str;
    }
    for(int i = start; i <= end; i++){
        result = result + str[i];
    }
    return result;
}

long long itc_len(string str){
    long long len = 0;
    for(int i = 0; str[i] != '\0'; i++){
        len++;
    }
    return len;
}

string reverse_str(string str){
    string result;
    for(int i = itc_len(str) - 1; i >= 0; i--){
        result += str[i];
    }
    return result;
}

string result_str(string first, string second, string znak){
    int flag = symbol(first) * symbol(second) * symbol(znak);
    string otvet, fir, sec;
    if(flag == 1){
        fir = first;
        sec = second;
        first = slice(first);
        second = slice(second);
        if(fir[0] == '-' and sec[0] == '-') return "-" + sum(first, second);
        return sum(first, second);
    }
    else if(flag == -1){
        fir = first;
        sec = second;
        first = slice(first);
        second = slice(second);
        if(fir[0] == '-' and (sec[0] != '-')) return  "-" + subtraction(first, second);
        else if(fir[0] == '-' and sec[0] == '-') return "-" + subtraction(first, second);
        return subtraction(first, second);
    }
    return otvet;
}
