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

    int coppied_arr[10];
    for(int i{0}; i<10; i++)
        coppied_arr[i]=arr[i];
    
    //Printing coppied array
    std::cout<<"\nCoppied array list :"<<std::endl;
    for (int i{0} ; i<10 ; i++)
        std::cout<<"Coppied array["<<i<<"] = "<<coppied_arr[i]<<std::endl;
} 