#include<iostream>
using namespace std;

int main(){
    int arr[10];
    for(int i=0;i<sizeof(arr)/sizeof(int);i++)
        arr[i]=i;
    cout<<"Elements in Array:\n\t";
    for(int i=0;i<sizeof(arr)/sizeof(int);i++)
        cout<<arr[i]<<'\t';
    return 0;
}