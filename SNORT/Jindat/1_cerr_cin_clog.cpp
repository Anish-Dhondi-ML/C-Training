// Session 1
// 13-02-2023
// write a program which includes cout,cerr,cin,clog


#include<iostream>

int main(){
    
    int a;

    std::cout<<"Enter a value : ";
    std::cin>>a;
    std::clog<<"Your value is taken !!!"<<std::endl;
    std::cerr<<"Entered value is : "<<a;
    return 0 ;
}
