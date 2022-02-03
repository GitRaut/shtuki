#include "header.h"

void ra(vector <int> &a){
    int count = a.size();
    vector<int> dop = a;
    if(count > 0){
        for(int i = count - 2; i >= 0; i -= 2){
            a[i] = dop[i + 1];
            a[i - 1] = dop[i];
        }
        a[count - 1] = dop[0];
    }
}

void rb(vector <int> &b){
    int count = b.size();
    vector<int> dop = b;
    if(count > 0){
        for(int i = count - 2; i >= 0; i -= 2){
            b[i] = dop[i + 1];
            b[i - 1] = dop[i];
        }
        b[count - 1] = dop[0];
    }
}

void rr(vector <int> &a, vector<int> &b){
    ra(a);
    rb(b);
}
