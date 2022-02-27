#include "mini_paint.h"

void reader(string way, vector <string> &res){
    ifstream in(way);
    string str;
    if(in.is_open()){
        while(getline(in, str)){
            res.push_back(str);
        }
    }
    in.close();
}
