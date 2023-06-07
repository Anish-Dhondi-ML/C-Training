#include<iostream>
using namespace std;

void sort(int a[],int size){
     for(int i=0;i<size;i++){
        for(int j=0;j<size-i-1;j++){
            if(a[j] < a[j+1]){
                swap(a[j],a[j+1]);
            }
        }
    }
}

int main(){
    int n=0;
    cout<<"Enter number of inputs: "<<endl;
    cin>>n;
    int a[n],result[n];
    for(int i=0;i<=n;i++){
        a[i] = i;
    }
    for(int i=0;i<n;i++){
        result[i] = a[i];
    }

    sort(result,n);
    for(int i=0;i<n;i++){
        cout<<result[i]<<endl;
    }
    return 0;
}