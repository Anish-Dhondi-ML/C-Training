#include<iostream>
using namespace std;

int c = 0;

void fun(){
    static int count = 0;
    count++;
    c = count;
}

int main(){

    int n=0;
    cout<<"Enter number of times the function to be printed: "<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        fun();
    }
    cout<<"Number of times function called is: "<<c<<endl;
    return 0;
}