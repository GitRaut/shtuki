#include "sup_pup.h"

string sum(string first, string second){
    long long max = max_len(first, second);
    int fir = 0, sec = 0;
    int point = 0, sum = fir + sec + point;
    string res;
    first = reverse_str(first);
    second = reverse_str(second);
    for(long long i = 0; i <= max; i++){
        fir = get_char_int(first, i);
        sec = get_char_int(second, i);
        if(sum > 9){
            point = 1;
        }
        else{
            point = 0;
        }
        sum = fir + sec + point;
        if(!(i == max and sum == 0)){
            res += sum % 10 + '0';
        }
    }
    return reverse_str(res);
}

string subtraction(string first, string second){
    int fir = 0, sec = 0, point = 0, sub = fir - sec - point, col;
    long long max = max_len(first, second), min = min_len(first, second);
    string res, result, minstr = min_str(first, second), maxstr = max_str(first, second);
    maxstr = reverse_str(maxstr);
    minstr = reverse_str(minstr);
    for(long long i = 0; i <= max; i++){
        fir = get_char_int(maxstr, i) - point;
        sec = get_char_int(minstr, i);
        sub = fir - sec;
        if(sub < 0 or fir < sec){
            point = 1;
            fir += 10;
        } else {
            point = 0;
        }
        sub = fir - sec;
        if(!(i == max and sub == 0)) res += sub % 10 + '0';
    }
    if(itc_ToInt(res) == 0) return "0";
    res = reverse_str(res);
    while(res[0] == '0'){
        res = itc_slice_str(res, 1, itc_len(res) - 1);
    }
    if(first == reverse_str(minstr)) res = "-" + res;
    return res;
}

string multiply(string first, string second){
    int fir = 0, sec = 0, point = 0, flag = fir * sec + point;
    long long max = max_len(first, second), min = min_len(first, second);
    vector <string> mass(min);
    string res, result, minstr = min_str(first, second), maxstr = max_str(first, second);
    maxstr = reverse_str(maxstr);
    minstr = reverse_str(minstr);
    for(long long i = 0; i < min; i++){
        for(int j = 0; j <= max; j++){
            fir = get_char_int(maxstr, j);
            sec = get_char_int(minstr, i);
            flag = fir * sec + point;
            if(j == max and point != 0) res += point % 10 + '0';
            if(flag > 9){
                point = flag / 10;
            }else{
                point = 0;
            }
            if(!(j == max)) res += flag % 10 + '0';
        }
        mass[i] = reverse_str(res) + count_of_nul(i);
        res = "";
    }
    for(int i = 0; i < min - 1; i++){
        mass[i + 1] = sum(mass[i], mass[i + 1]);
    }
    return mass[min - 1];
}

string del(string first, string second){
    long long len = itc_len(first), len2 = itc_len(second);
    string fir, sec = second, result, ostat;
    fir = itc_slice_str(first, 0, len2 - 1);
    if(fir != second and fir == min_str(fir, second)){
        fir = itc_slice_str(first, 0, len2);
    }
    long long i = itc_len(fir) - 1, iter = 0;
    while(i <= len - 1){
        if( itc_ToInt(fir) != 0){
            while(sec != max_str(fir, sec)){
                sec = sum(sec, second);
                iter = iter + 1;
            }
        }
        if(subtraction(fir, sec) != "0"){
            sec = subtraction(sec, second);
        }
        else{
            iter++;
        }
        fir = subtraction(fir, sec);
        result += itc_ToString(iter);
        sec = second;
        iter = 0;
        i++;
        fir = fir + first[i];
        if(itc_slice_str(first, i, len - 1) == min_str(first, second)){
            result += "0";
        }
    }
    return result;
}
