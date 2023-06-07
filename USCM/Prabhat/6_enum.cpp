// The assignment program in C++ training on 27/02/2023
// This program to practice enum
#include<iostream>
#include<cstdio>

enum class  month {jan=1,feb,mar,apr,may,jun,jul,aug,sep,oct,nov,dec};
int main(){
    month m;

    int a=(int)month::dec;
    int ch;
    
    std::cin>>ch;
    m=(month)ch;
    int b=(int)m;
    
    std::cout<<a<<"\n"<<b<<std::endl;
}