#include<iostream>
using namespace std;

int main(){

    int a[] = {2,3,1,8,1,7,9,6,5};
    int size = sizeof(a)/sizeof(int);
    int m = 0;
    int p = size-1;
    while(m<p){
        swap(a[m],a[p]);
        m++;
        p--;
    }
    for(int i=0;i<size;i++){
        cout<<a[i]<<endl;
    }
    return 0;
}