#include<iostream>
using namespace std;

int main()
{
    int x;
    cout<<"Enter the number : ";
    cin>>x;
    if(x%2==0)
        cout<<"The value "<<x<<" is an even number";
    else
        cout<<"The value "<<x<<" is an odd number";
}