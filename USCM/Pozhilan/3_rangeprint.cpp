#include<iostream>
using namespace std;

int main(){
    int *ptr1,*ptr2,val1,val2;
    cout<<"Enter lower limit and upper limit of the range: ";
    cin>>val1>>val2;
    ptr1=&val1;
    ptr2=&val2;
    for(int i=*ptr1;i<=*ptr2;i++){
        cout<<i<<'\t';
    }
    return 0;
}