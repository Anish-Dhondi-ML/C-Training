#include<iostream>
using namespace std;
int main()
{
    int i=10;
    cout<<"Printing numbers from 10 to 1 using for loop :"<<endl;
    for(;i>=0;i--)
        cout<<i<<endl;
    cout<<endl;
    
    i=10;
    cout<<"Printing numbers from 10 to 1 using while loop :"<<endl;
    while(i>=0)
        cout<<i--<<endl;
    cout<<endl;
    
    i=10;
    cout<<"Printing numbers from 10 to 1 using do while loop :"<<endl;
    do
    {
       cout<<i--<<endl; 
    } while (i>=0);
}