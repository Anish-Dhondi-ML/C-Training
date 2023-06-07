#include<iostream>
using namespace std;

int main(){
    int i=1,sum=0;
    do{
        sum+=i;
    }while(++i<=10);
    cout<<sum;
    return 0;
}