#include<iostream>
using namespace std;

int main(){
    
    int m,p;
    cin>>m>>p;
    int sum=0;
    while(m<=p){
        sum+=m;
        m++;
    }
    cout<<sum;
    return 0;
}