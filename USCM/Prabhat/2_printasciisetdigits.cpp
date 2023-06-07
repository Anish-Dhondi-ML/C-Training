// The program in C++ training on 15/02/2023
// This program to print from 0 to 9 in char without knowing its ASCII value
#include<iostream>

int main(){
    char digit{'0'};
    
    while(isdigit(int(digit))){
        std::cout<<digit<<std::endl;
        digit=int(digit)+1;
        //digit++;
    } 
}