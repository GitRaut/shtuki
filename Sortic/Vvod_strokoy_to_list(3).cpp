#include "header.h"

int itc_str_to_int(char a)
{
    int ot=-1;
    if(a=='0') ot=0;
    else if(a=='1') ot=1;
    else if(a=='2') ot=2;
    else if(a=='3') ot=3;
    else if(a=='4') ot=4;
    else if(a=='5') ot=5;
    else if(a=='6') ot=6;
    else if(a=='7') ot=7;
    else if(a=='8') ot=8;
    else if(a=='9') ot=9;
    //else return 0;
    return ot;
}
string itc_slice_str(string str,int start, int endd)
{
    long long l;
    l=str.size();
    string n="";
    if(start>endd)
    {
        return str;
    }
    if(endd>l-1)
    {
        endd=l-1;
    }
    for(int i=start;i<endd+1;i++)
    {
        n+=str[i];
    }
    return n;
}
void vvod_str(vector<int> &a,vector<int> &b,string vvod)
{
    string vvod_number="";
    string vvod_commands="";
    int i=0;

    int k=0;
    for(int j=0;j<vvod.size();j++)
    {
        if(vvod[j]=='!')
            k=1;
    }
    if(k!=1){print_error();return;}

    while(vvod[i]!='!')
    {
        i++;
    }
    vvod_number=itc_slice_str(vvod,0,i-1);
    vvod=itc_slice_str(vvod,i+1,vvod.size());
    nubmer_string_to_list(vvod_number,a);
}
int str_num_to_int(string str)
{
    int k=1;
    int num=0;
    for(int i=0;i<str.size();i++)
    {
       num+=k*itc_str_to_int(str[str.size()-i-1]);
       k=k*10;
    }
    return num;
}

void nubmer_string_to_list(string vvod, vector <int> &a)
{
    string zapis="";
    vvod+=' ';
    for(int i=0;i<vvod.size();i++)
    {
        while(vvod[i]!=' ')
        {
          zapis+=vvod[i];
          i++;
        }
        if(zapis[0]=='-')
        {
            if(zapis.size()!=0)
            {
               zapis=itc_slice_str(zapis,1,zapis.size());
               a.push_back(str_num_to_int(zapis)*(-1));
            }

        }else{
            if(zapis.size()!=0)
                a.push_back(str_num_to_int(zapis));
        }
        zapis="";
    }
}

void command_to_list(string vvod,vector <string> &com)
{
    string zapis="";
    vvod+=' ';
    for(int i=0;i<vvod.size();i++)
    {
        while(vvod[i]!=' ')
        {
          zapis+=vvod[i];
          i++;
        }
        if(zapis.size()!=0)
        {
           com.push_back(zapis);
           zapis="";
        }

    }
}


