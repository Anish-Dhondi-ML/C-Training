// The assignment program in C++ training on 27/02/2023
// This program to practice function
#include<iostream>
int fun(){
    return 1;
}

int main(){
    
    int a,* ptr;
    ptr = &fun();
    std::cout<<&a<<"\n"<<&fun()<<std::endl;
    
}

