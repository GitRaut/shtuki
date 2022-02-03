#include "header.h"

void pa(vector <int> &a, vector <int> &b){
    int count_a = a.size(), count_b = b.size();
    vector <int> dop1, dop2;
    if(count_b > 0){
        dop1.push_back(b[0]);
        for(int i = 0; i < count_a; i++){
            dop1.push_back(a[i]);
        }
        a = dop1;
        for(int i = 1; i < count_b; i++){
            dop2.push_back(b[i]);
        }
        b = dop2;
    }
}

void pb(vector <int> &a, vector <int> &b){
    int count_a = a.size(), count_b = b.size();
    vector <int> dop1, dop2;
    if(count_a > 0){
        dop1.push_back(a[0]);
        for(int i = 0; i < count_b; i++){
            dop1.push_back(b[i]);
        }
        b = dop1;
        for(int i = 1; i < count_a; i++){
            dop2.push_back(a[i]);
        }
        a = dop2;
    }
}
