// The assignment program in C++ training on 17/02/2023
// This program to practice pointer
#include<iostream>

int main(){
    int p=100;
    int* ptr{&p};
    std::cout<<"Address: "<<&p<<" value: "<<*ptr;
}