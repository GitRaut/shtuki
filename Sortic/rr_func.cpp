#include "header.h"

void rra(vector <int> &a){
    int count = a.size();
    vector<int> dop = a;
    if(count != 0){
        for(int i = 1; i < count; i += 2){
            a[i] = dop[i - 1];
            a[i + 1] = dop[i];
        }
        a[0] = dop[count - 1];
    }
}

void rrb(vector <int> &b){
    int count = b.size();
    vector<int> dop = b;
    if(count != 0){
        for(int i = 1; i < count; i += 2){
            b[i] = dop[i - 1];
            b[i + 1] = dop[i];
        }
        b[0] = dop[count - 1];
    }
}

void rrr(vector <int> &a, vector<int> &b){
    rra(a);
    rrb(b);
}
