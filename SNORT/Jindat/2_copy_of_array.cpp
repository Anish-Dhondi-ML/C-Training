// Session 2
// 16-02-2023
// Write a program to create a copy of an array.


#include<iostream>

int main(){
    
    int arr[100];

    for(int i=50; i<100; i++)
        arr[i]=i;
    
    
    for (int i=50 ; i<100 ; i++)
        std::cout<<"Original Array : "<< arr[i] << std::endl;

    int copyarr[100];
    for(int i=50; i<100; i++)
        copyarr[i]=arr[i];
    
    for (int i=50 ; i<100 ; i++)
        std::cout<<"Copy of the Original Array : "<< copyarr[i] <<std::endl;
} 
