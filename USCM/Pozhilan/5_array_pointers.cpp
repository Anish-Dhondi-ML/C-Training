#include<iostream>
using namespace std;

int main(){
    int arr1[5]{7,-11,15,3,9},arr2[4]{11,19,8,4};
    int *a [10]{&arr1[0],&arr1[1],&arr1[2],&arr1[3],&arr1[4],&arr2[0],&arr2[1]};
    for(int i=0;i<10;i++){
        cout<<*(*a+i)<<'\t';
    }
    cout<<endl<<"............................."<<endl;
    for(int i=0;i<10;i++){
        cout<<*a[i]<<'\t';
    }
    return 0;
}