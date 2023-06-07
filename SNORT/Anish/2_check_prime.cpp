// Session 2
// 16-02-2023
// Write program to check if an array has prime numbers and give count of it.

#include<iostream>

int Chk_Prime(int ele){

    if(ele == 1){
        return 0;
    }else{
         for(int i=2;i<=ele/2;i++){
               if(ele % i == 0){
                 return 0;
               }
         }
    }
    return 1;
}
int main(){
    
    int arr[] = {2,5,7,8,4,6,11,23,99,10,107,1,89,73,79,43,59};
    int cnt = 0;
    std::cout<<"The prime numbers in the array : "<<std::endl;
    int n = sizeof(arr)/sizeof(int);
    for(int i=0;i<n;i++){
        if(Chk_Prime(arr[i])){
            std::cout<<" "<<arr[i];
            cnt++;
        }
    }
    std::cout<<std::endl;
    std::cout<<"No of prime numbers: "<<cnt<<std::endl;
    return 0;
}