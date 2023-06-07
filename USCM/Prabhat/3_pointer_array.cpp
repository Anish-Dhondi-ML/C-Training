// The assignment program in C++ training on 17/02/2023
// This program to practice pointer and array
#include<iostream>

int main(){
    int arr[5]{34,67,89,45,77};
    int* ptr{&arr[0]};
    for (int i = 0; i < 5; i++){
        std::cout<<*(ptr+i)<<"\n";
    }
    
}