#include<iostream>
using namespace std;

int main(){
    int a[]={1,25,5,4,75};
    int min = INT16_MAX;
    int max = INT16_MIN;
    int size = sizeof(a)/sizeof(int);
    for(int i=0;i<size;i++){
        if(a[i]<min){
            min = a[i];
        }
        if(a[i]>max){
            max = a[i];
        }
    }
    cout<<"The maximum element is: "<<max<<endl;
    cout<<"The minimum element is: "<<min<<endl;
    return 0;
}