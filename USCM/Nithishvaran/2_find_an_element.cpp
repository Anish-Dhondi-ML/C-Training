#include<iostream>
using namespace std;

int main(){
    int a[] = {2,1,8,3,4,9};
    int size = sizeof(a)/sizeof(int);
    int flag = 0;
    int m=0;
    cout<<"Enter the element to be searched: "<<endl;
    cin>>m;
    for(int i=0;i<size;i++){
        if(a[i] == m){
            cout<<"Element "<<m<<" present in the position: "<<i<<endl;
            flag = 1;
        }
    }
    if(flag == 0){
        cout<<"Entered element is not present in the given array: "<<endl;
    }
    return 0;
}