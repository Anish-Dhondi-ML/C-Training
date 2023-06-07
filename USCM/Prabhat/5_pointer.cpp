// The assignment program in C++ training on 21/02/2023
// This program to practice pointer
#include<iostream>
#include<cstdio>

int main(){
    
    int *ptr = new int[10];
    
    for(int i{0}; i<10; i++){
        *(ptr+i)=i;
        std::cout<<(ptr+ i )<<"\t"<<*(ptr+i)<<std::endl;
}
}