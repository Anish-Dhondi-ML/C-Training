// The assignment program in C++ training on 16/02/2023
// This program to insert index value in the array
#include<iostream>

int main(){
    
    int arr[10];

    for(int i{0}; i<10; i++)
        arr[i]=i;
    
    //Printing array 1
    std::cout<<"\n array list :"<<std::endl;
    for (int i{0} ; i<10 ; i++)
        std::cout<<"array["<<i<<"] = "<<arr[i]<<std::endl;
    
   
} 