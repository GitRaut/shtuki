#include "header.h"

int max_num(vector <int> a){
    int count = a.size();
    int max = 0;
    if(count > 0){
        for(int i = 0; i < count; i++){
            if(a[i] > max){
                max = a[i];
            }
        }
    }
    return max;
}

int min_num(vector <int> a){
    int count = a.size();
    int min = max_num(a);
    if(count > 0){
        for(int i = 0; i < count; i++){
            if(a[i] < min){
                min = a[i];
            }
        }
    }
    else{
        return 0;
    }
    return min;
}

int max(int a, int b){
    if(a > b){
        return a;
    }
    return b;
}

int min(int a, int b){
    if(a < b){
        return a;
    }
    return b;
}
