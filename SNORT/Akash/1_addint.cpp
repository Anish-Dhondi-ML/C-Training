#include<iostream>

int main()
{
    int i=1,j=1;
    std::cout<<"Addition of two numbers declared within the program"<<std::endl;
    std::cout<<i+j<<std::endl;

    std::cout<<"Addition of two numbers given by the user"<<std::endl;
    std::cout<<"Enter number 1 and 2: ";
    std::cin>>i>>j;
    std::cout<<i+j<<std::endl;
}