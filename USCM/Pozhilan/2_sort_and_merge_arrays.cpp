#include<iostream>
using namespace std;

int main(){

    int arr1[]{5,76,99,23,56,-43,-5,457,-23,0,34}, arr2[]{-53,243,-434,0,34,0,245},arr3[(sizeof(arr1)/sizeof(int))+(sizeof(arr2)/sizeof(int))],temp;

    for(int i=0;i<sizeof(arr1)/sizeof(int);i++){
        for(int j=i;j<sizeof(arr1)/sizeof(int);j++){
            if(arr1[i]>arr1[j]){
                temp=arr1[i];
                arr1[i]=arr1[j];
                arr1[j]=temp;
            }
        }
    }
   
    for(int i=0;i<sizeof(arr2)/sizeof(int);i++){
        for(int j=i;j<sizeof(arr2)/sizeof(int);j++){
            if(arr2[i]>arr2[j]){
                temp=arr2[i];
                arr2[i]=arr2[j];
                arr2[j]=temp;
            }
        }
    }

    int i{0},j{0},k{0};

    while(j<sizeof(arr2)/sizeof(int)){
        if(arr1[i]==arr2[j]){
            arr3[k++]=arr1[i++];
            arr3[k++]=arr2[j++];
        }
        else if(arr1[i]<arr2[j])
            arr3[k++]=arr1[i++];
        else
            arr3[k++]=arr2[j++];
    }
    while(i<sizeof(arr1)/sizeof(int)){
        arr3[k++]=arr1[i++];
    }

    cout<<"The elements in sorter and merged array are"<<endl;
    for(int i=0;i<sizeof(arr3)/sizeof(int);i++){
        cout<<arr3[i]<<'\t';
    }        

    return 0;
}