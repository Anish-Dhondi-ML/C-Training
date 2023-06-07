#include<iostream>
using namespace std;

int main(){

    int a[] = {4,2,8,1,0};
    int size = sizeof(a)/sizeof(int);

for(int i=0;i<size;i++){
    for(int j=0;j<size-i-1;j++){
        if(a[j] > a[j+1]){
                swap(a[j],a[j+1]);
            }
        }
    }

    for(int i=0;i<size;i++){
        cout<<a[i]<<endl;
    }
    return 0;
}