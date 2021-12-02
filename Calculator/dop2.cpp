#include "sup_pup.h"

string check_sum(string first, string second){
    if(first == "0" and second == "0"){
        return "0";
    }
    return sum(first, second);
}

string check_minus(string first, string second){
    if(first == "0" and second == "0"){
        return "0";
    }
    return subtraction(first, second);
}

string slice_null(string num){
    if(itc_ToInt(num) == 0){
        return num;
    }
    while(num[0] == '0'){
        num = itc_slice_str(num, 1, itc_len(num) - 1);
    }
    return num;
}

string check_mult(string first, string second){
    if(second == "0"){
        return "0";
    }
    else if(second == "0" and first == "0"){
        return "0";
    }
    return multiply(first, second);
}
