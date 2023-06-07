#include<iostream>
using namespace std;

int main(){
    int arr[]{0,1,2,3,4,5,6,7,8,9},len=sizeof(arr)/sizeof(int);
    for(int i=0;i<len/2;i++){
        arr[i]=arr[len-1-i]+arr[i];
        arr[len-1-i]=arr[i]-arr[len-1-i];
        arr[i]=arr[i]-arr[len-1-i];
    }
    for(int i=0;i<len;i++)
        cout<<arr[i]<<'\t';
}