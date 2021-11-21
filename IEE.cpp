#include<iostream>
#include<string>

using namespace std;

long long len(string str){
    long long len = 0;
    for(int i = 0; str[i] != '\0'; i++){
        len++;
    }
    return len;
}

string ToString(int num){
    string res = "", result = "";
    int point;
    if(num == 0){
        return "0";
    }
    while(num > 0){
        point = num % 10;
        res += '0' + point;
        num = num / 10;
    }
    for(int i = len(res) - 1; i >= 0; i--){
        result += res[i];
    }
    return result;
}

long long ToInt(string str){
    long long num = 0;
    for(int i = 0; i < len(str); i++){
        if(str[i] >= '0' and str[i] <= '9'){
            num = num * 10 + (str[i] - '0');
        }
    }
    return num;
}

string itc_slice_str(string str, int start, int end){
    long long lenght = len(str);
    string result;
    if((end > lenght) and (start < lenght)){
        for(int i = start; i < lenght; i++){
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

string bin_num_drob(string drob){
    long long lend = len(drob), posl = ToInt(drob), step = 1;
    string nc;
    for(int i = 0; i < lend; i++){
        step = step * 10;
    }
    for(int i = 0; i < 23; i++){
        posl = posl * 2;
        if(len(ToString(posl)) > len(drob)){
            nc += "1";
        } else{
            nc += "0";
        }
        posl = posl % step;
    }
    return nc;
}

long long bin_num_cel(long long number){
    int cif;
    long long result = 0, chislo = 0, len = 0;
    while(number > 0){
        cif = number % 2;
        chislo = chislo * 10 + cif;
        number = number / 2;
        len++;
    }
    while(len > 0){
        cif = chislo % 10;
        result = result * 10 + cif;
        chislo = chislo / 10;
        len--;
    }
    return result;
}

string get_mantis(string str){
    long long lenght = len(str), num;
    string point, bin_cel, drob, mantis;
    for(int i = 0; i < lenght; i++){
        if(str[i] >= '0' and str[i] <= '9'){
            point += str[i];
        }
        if(str[i] == ',' or str[i] == '.'){
            num = ToInt(point);
            num = bin_num_cel(num);
            bin_cel += ToString(num);
            point = "";
        }
        if(str[i + 1] == '\0'){
            drob += point;
            point = "";
        }
    }
    string bin_drob = bin_num_drob(drob);
    if(ToInt(bin_cel) != 0){
        if(ToInt(bin_cel) != 1){
            mantis += itc_slice_str(bin_cel, 1, len(bin_cel) - 1);
            mantis += bin_drob;
            mantis = itc_slice_str(mantis, 0, 22);
        }
        else{;
            mantis += bin_drob;
            mantis = itc_slice_str(mantis, 0, 22);
        }
    }
    if(ToInt(bin_cel) == 0){
        while(ToInt(bin_cel) != 1){
            bin_cel += bin_drob[0];
            bin_drob = itc_slice_str(bin_drob, 1, len(bin_drob) - 1);
            mantis += bin_drob;
        }
        mantis += "0";
    }
    return mantis;
}

string get_exponent(string str){
    long long lenght = len(str), num;
    string point, bin_cel, drob, mantis;
    for(int i = 0; i < lenght; i++){
        if(str[i] >= '0' and str[i] <= '9'){
            point += str[i];
        }
        if(str[i] == ',' or str[i] == '.'){
            num = ToInt(point);
            num = bin_num_cel(num);
            bin_cel += ToString(num);
            point = "";
        }
        if(str[i + 1] == '\0'){
            drob += point;
            point = "";
        }
    }
    string bin_drob = bin_num_drob(drob);
    int step = 0;
    if(ToInt(bin_cel) != 0){
        mantis += itc_slice_str(bin_cel, 1, len(bin_cel) - 1);
        mantis += bin_drob;
        mantis = itc_slice_str(mantis, 0, 22);
        step = len(bin_cel) - 1;
    }
    if(ToInt(bin_cel) == 0){
        while(ToInt(bin_cel) != 1){
            bin_cel += bin_drob[0];
            bin_drob = itc_slice_str(bin_drob, 1, len(bin_drob) - 1);
            mantis += bin_drob;
            step--;
        }
        mantis += "0";
    }
    num = 127 + step;
    string expp = ToString(bin_num_cel(num));
    string exp;
    if(len(expp) < 8){
        while(len(exp) < 8 - len(expp)){
            exp += '0';
        }
        exp += expp;
    } else {
        exp += expp;
    }
    return exp;
}

string func(string str){
    string znak = "0", result;
    if(str[0] == '-'){
        znak = "1";
    }
    if(str == "0" or str == "0.0" or str == "0,0"){
        result = znak;
        for(int i = 0; i < 31; i++){
            result += '0';
        }
    }
    else if (str == "inf" || str == "INF" || str == "Inf" || str == "infinity" || str == "INFINITY" || str == "Infinity")
	{
		result = znak;
		for (int i = 0; i < 8; i++){
			result += '1';
		}
		for (int i = 0; i < 23; i++){
			result += '0';
		}
	}
	else if (str == "nan" || str == "NaN" || str == "NAN")
	{
		result = znak;
		for (int i = 0; i < 31; i++){
			result += '1';
		}
	}
	else{
        result += znak;
        result += get_exponent(str);
        result += get_mantis(str);
	}
	return result;
}

int main()
{
    cout << func("1.21");
}
