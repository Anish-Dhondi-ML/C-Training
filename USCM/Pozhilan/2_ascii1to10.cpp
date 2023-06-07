#include<iostream>
using namespace std;

int main(){
    for(int i=0;i<=10;i++)
        cout<<i<<'='<<'0'+i<<'\t';
    cout<<"\n-----------------------------------------------------------------"<<endl;
    for(int i=48;i<58;i++)
        cout<<(char)i<<' ';
    return 0;
}