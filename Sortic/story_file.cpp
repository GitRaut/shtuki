#include "header.h"
string story(){
    ifstream inout("vvod.txt", ios::in);
    string str;
    int i = 1;
    if (inout.is_open())
    {
        while ( getline (inout,str) )
        {
            str = str + "\n";
            return str;
        }
    }
    inout.close();
}

void reader(string vvod){
    ofstream out("Story.txt", ios::app);
    if (out.is_open())
    {

        //out<<endl;

        out << vvod << endl;// <<" —————— "<<res << endl;

    }
    out.close();
}
