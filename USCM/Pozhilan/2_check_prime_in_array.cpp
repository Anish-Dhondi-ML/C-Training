#include<iostream>
using namespace std;

int main(){
    int arr[50],count;
    bool truth=false;
    cout<<"Enter the number of elements in array: ";
    cin>>count;
    cout<<"Enter the elements in array"<<endl;
    for(int i=0;i<count;i++)
        cin>>arr[i];   
    for(int i=0;i<count;i++){
        int count1{0};
        for(int j=1;j<=arr[i];j++){
            if(arr[i]%j==0)
                count1++;
        }
        if(count1==2){
            cout<<arr[i]<<" is a prime number"<<endl;
            truth=true;
        }
    } 
    if(!truth)
        cout<<"Prime number not found in array.";
    return 0;
}