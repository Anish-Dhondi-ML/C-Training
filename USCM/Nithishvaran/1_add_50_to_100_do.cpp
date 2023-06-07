#include<iostream>
using namespace std;

int main(){

    int m,p;
    cin>>m>>p;
    int sum=0;
    do{
        sum+=m; 
        m++;
    }while(m<=p);
    cout<<sum;
    return 0;
}
