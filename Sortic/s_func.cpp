#include "header.h"

void sa(vector <int> &a){
    int count_a = a.size();
    int point;
    if(count_a > 1){
        point = a[0];
        a[0] = a[1];
        a[1] = point;
    }
}

void sb(vector <int> &b){
    int count_b = b.size();
    int point;
    if(count_b > 1){
        point = b[0];
        b[0] = b[1];
        b[1] = point;
    }
}

void ss(vector <int> &a, vector <int> &b){
    sa(a);
    sb(b);
}
