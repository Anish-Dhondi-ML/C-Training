// The assignment program in C++ training on 14/02/2023
// This program tells whether the number is odd or even

#include<iostream>
int main(){
    
    int a=0;
    std::cout<<"Enter the number : ";
    std::cin>>a;
    if(a%2==0)
        std::cout<<"The value "<<a<<" is a even number"<<std::endl;
    else
        std::cout<<"The value "<<a<<" is a odd number"<<std::endl;
}