// Session 1
// 14-02-2023
// Assignment question : Write a program to test an integer value to determine if it is odd or even. Make sure your output is clear and complete. In other words, don’t just output yes or no. Your output should tell: The value 4 is an even number. (Find the remainder operator)

#include<iostream>


int main(){

    int i;
    std::cout<<"Enter a Number : ";
    std::cin>>i;

    if(i % 2 == 0)
        std::cout<<"Entered Number "<<i<<" is even !"<<std::endl;
    else
        std::cout<<"Entered Number "<<i<<" is odd !"<<std::endl;

    return 0;
}
