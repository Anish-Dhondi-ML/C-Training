// Session 1
// 13-02-2023
// Find range by taking two input values 

#include<iostream>
using namespace std;

int main()
{
    int i,j;
    cout<<"Enter two numbers :"<<endl;
    cin>>i>>j;
    if(i>j){
        cout<<"The Range btw "<<j<<" and "<<i<<" : "<<endl;
    for(int a=j+1;a<i;a++)
        cout<<a<<endl;

    }
    else {
        cout<<"The Range btw "<<i<<" and "<<j<<" : "<<endl;
    for(int a=i+1;a<j;a++)
        cout<<a<<endl;
    }
    return 0;
    

}
