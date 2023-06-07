#include<iostream>
using namespace std;

int main(){
    int inp,arr[10]{0};
    cout<<"Enter the number from 0 to 10:(Press any letter to exit)"<<endl;
    while(cin>>inp){
        if(inp>10 || inp<0)
            cerr<<"Enter a valid number..."<<endl;
        for(int i=0;i<10;i++){
            if(inp==i){
                arr[i]++;
                break;
            }
        }
    }
    cout<<"The input count of keys from 1 to 10 respectively are:"<<endl;
    for(int i=0;i<10;i++)
        cout<<i<<": "<<arr[i]<<'\t';
    return 0;
}