#include "sup_pup.h"

void story(){
    ifstream inout("D:\\Code\\calculator\\History.txt", ios::in);
    string str;
    if (inout.is_open())
    {
        while ( getline (inout,str) )
        {
            str = str + "\n";
            print(str);
        }
    }
    inout.close();
}

void reader(string ans, string res){
    ofstream out("D:\\Code\\calculator\\History.txt", ios::app);
    if (out.is_open())
    {
        out << ans << res << endl;
    }
    out.close();
}
