#include<iostream>
using namespace std;

int main(){
    int n=0;
    cout<<"Enter the value 'n' : ";
    cin>>n;
    if(n%2 == 0){
        cout<<"Value "<<n<<" is a even number"<<endl;
    }else{
        cout<<"Value "<<n<<" is a odd number"<<endl;
    }
    return 0;
}