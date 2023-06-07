#include<iostream>
using namespace std;


void bubble_sort(int *a,int n){

    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(*(a+j) > *(a+(j+1))){
                swap(*(a+j), *(a+(j+1)));
            }
        }
    }
}

void insertion_sort(int *a,int n){

    for(int i=1;i<n;i++){
        for(int j=i;j>0;j--){
             if(*(a+j) < *(a+(j-1))){
                  swap(*(a+j),*(a+(j-1)));
             }
        }
    }
}

int main(){
    int a[] = {3,2,6,9,7,0,1};
    int b[] = {2,3,6,6,0,7,1};
    
    int size = sizeof(a)/sizeof(int);
    bubble_sort(a,size);
    for(int i=0;i<size;i++){
        cout<<a[i];
    }
    cout<<endl;

    insertion_sort(b,size);
    for(int i=0;i<size;i++){
        cout<<b[i];
    }
    
    return 0;
}