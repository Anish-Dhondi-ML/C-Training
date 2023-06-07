// Session 1 Homework
// 13-02-2023
// write a prgm which includes cout,cerr,cin,clog


#include<iostream>

int main(){
    
    int i;

    std::cout<<"Enter a value : ";
    std::cin>>i;
    std::clog<<"Your value is taken !!!"<<std::endl;
    std::cerr<<"Entered value is : "<<i;
    return 0 ;
}