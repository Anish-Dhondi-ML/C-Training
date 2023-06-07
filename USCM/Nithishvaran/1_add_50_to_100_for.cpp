#include<iostream>
using namespace std;

int main(){

    int m,p;
    cin>>m>>p;
    int sum=0;
    for(int i=m; i>=m && i<=p;i++){
        sum+=i;
    }
    cout<<sum;
    return 0;
}