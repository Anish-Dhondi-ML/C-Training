// The assignment program in C++ training on 20/02/2023
// This program to practice pointer
#include<iostream>
#include<cstdio>

int main(){
    int i{23},j{35},k{299},l{102};
    int *ptr[5];
    ptr[0]=&i;
    ptr[1]=&j;
    ptr[2]=&k;
    ptr[3]=&l;

    for(int p{0}; p<4; p++)
        std::cout<<ptr[p]<<"\t"<<*ptr[p]<<std::endl;
}