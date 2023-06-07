#include<iostream>
using namespace std;


int main(){
    int arr1[10];
    for(int i=0;i<sizeof(arr1)/sizeof(int);i++)
        arr1[i]=i;
    int arr2[10];
    for(int i=0;i<10;i++)
        arr2[i]=arr1[i];
    cout<<"Elements in arr2:\n\t";
    for(int i=0;i<sizeof(arr2)/sizeof(int);i++)
        cout<<arr2[i]<<'\t';
    return 0;
}
