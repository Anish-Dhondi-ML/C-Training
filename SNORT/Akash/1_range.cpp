#include<iostream>
using namespace std;
int main ()
{
    int start,end;
    cout<<"Enter the starting number and the ending number : ";
    cin>>start>>end;
    
    for(int i=start+1;i<end;i++)
        cout<<endl<<i;
}