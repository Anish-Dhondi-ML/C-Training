#include<iostream>
using namespace std;

int main(){
    int arr1[]{4,2,3,5,763,42,46,8,68,67},arr2[]{5,3,7,8,3,44,72,104,68},arr3[10],k{0};
    int *ptr1=arr1,*ptr2=arr2,*ptr3=arr3;
    for(int i=0;i<sizeof(arr1)/sizeof(int);i++){
        for(int j=0;j<sizeof(arr2)/sizeof(int);j++){
            if(*(ptr1+i)==*(ptr2+j)){
                *(ptr3+(k++))=i;
            }
        }
    }
    cout<<"Common elements index of array 1 are"<<endl;
    for(int i=0;i<k;i++)
        cout<<*(ptr3+i)<<'\t';
    return 0;
}