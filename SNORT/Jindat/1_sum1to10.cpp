// Session 1
// 13-02-23
// Print sum of 10 numbers using While loop



#include<iostream>
using namespace std;

int main(){
    int i=0;
    int sum=0;
    
    while(i<=10)
      {
        sum += i;
        i++;
      }
    cout<<"The sum of numbers are  "<<sum<<endl;
}
