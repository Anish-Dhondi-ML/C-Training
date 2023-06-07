#include<iostream>
using namespace std;

int main(){
    int arr[]{-27,54,36,428,99,126,38,49,43,1,11,0,-17};
    for(int i=0;i<sizeof(arr)/sizeof(int)-1;i++){
        for(int j=0;j<sizeof(arr)/sizeof(int)-i-1;j++){
            if(arr[j]>arr[j+1]){
                arr[j]=arr[j]+arr[j+1];
                arr[j+1]=arr[j]-arr[j+1];
                arr[j]=arr[j]-arr[j+1];
            }
        }   
    }
    cout<<"Array after Bubble sort: ";
    for(int i=0;i<sizeof(arr)/sizeof(int);i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}