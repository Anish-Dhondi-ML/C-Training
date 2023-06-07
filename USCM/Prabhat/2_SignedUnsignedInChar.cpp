// The program in C++ training on 15/02/2023
// This program to 
#include<iostream>

int main(){
    char chi=-129;
    // chi=256 will show error or warning of overflow
    // chi=-129 will show error or warning of overflow

    unsigned char ch=255;
    
    std::cout<<int(chi)<<std::endl<<int(ch)<<std::endl;
        
}