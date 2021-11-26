#include "sup_pup.h"

string count_of_nul(long long iter){
    string result = "";
    for(long long i = 0; i < iter; i++){
        result += "0";
    }
    return result;
}

void check_value(string znak){
    if(znak != "+" and znak != "-" and znak != "*"){
        error();
    }
}
