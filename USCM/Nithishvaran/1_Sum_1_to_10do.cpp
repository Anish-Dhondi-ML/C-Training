#include<iostream>
using namespace std;

int main(){
    
    int i=0;
    int sum=0;

    do{
      i++;
      sum+=i;
    }while(i<10);
    cout<<sum;
    
    return 0;
}