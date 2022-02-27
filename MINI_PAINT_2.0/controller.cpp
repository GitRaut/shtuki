#include "mini_paint.h"

void controller(string way){
    bool checker = check_way(way);
    int point = 0, way_len = len(way);
    vector <string> mass;
    if(checker && count_of_arg(way) == "save"){
        point = slice_point(way);
        way = itc_slice_str(way, 0, point - 2);
        reader(way, mass);
        way_len = len(way);
        way = itc_slice_str(way, 0, way_len - 14);
        render(mass, 1);
        cout << endl;
        print("SAVED", 100, "G");
    }
    else if(checker){
        reader(way, mass);
        render(mass, 0);
    }
}
//D:\Code\MINI_PAINT\operation.it
