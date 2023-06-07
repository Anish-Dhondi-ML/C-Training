#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    int i,j;
    char str[2][4]={"kar","rk"};
    char (*ptr)[2][4]=&str;
    for(i=0;i<2;i++)
    {
        cout<<(*ptr)[i]<<"-";
        for(j=0;j<4;j++)
        {
            cout<<(*ptr)[i][j]<<" ";
        }
        cout<<endl;
    }
}
