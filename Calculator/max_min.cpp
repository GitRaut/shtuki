#include "sup_pup.h"

long long max_len(string first, string second){
    long long len_first = itc_len(first), len_second = itc_len(second);
    if(len_first > len_second){
        return len_first;
    }
    return len_second;
}

long long min_len(string first, string second){
    long long len_first = itc_len(first), len_second = itc_len(second);
    if(len_first < len_second){
        return len_first;
    }
    return len_second;
}

string max_str(string first, string second){
    long long len1 = itc_len(first);
    long long len2 = itc_len(second);
    if(first == second){
        return first;
    }
    else if(first[0] == '-' and (second[0] == '+' or isInt(second[0]) == 1)){
        return second;
    }
    else if(len1 == len2){
        for(int i = 0; i < len1; i++){
            if(char_to_int(first[i]) > char_to_int(second[i])){
                return first;
            }
            else if(char_to_int(first[i]) < char_to_int(second[i])){
                return second;
            }
        }
    }
    else if(len1 > len2){
        return first;
    }
    else{
        return second;
    }
}

string min_str(string first, string second){
    long long len1 = itc_len(first), len2 = itc_len(second);
    if(first == second){
        return first;
    }
    else if(first[0] == '-' and (second[0] == '+' or isInt(second[0]) == 1)){
        return first;
    }
    else if(len1 == len2){
        for(int i = 0; i < len1; i++){
            if(char_to_int(first[i]) < char_to_int(second[i])){
                return first;
            }
            else if(char_to_int(first[i]) > char_to_int(second[i])){
                return second;
            }
        }
    }
    else if(len1 < len2){
        return first;
    }
    else{
        return second;
    }
}
