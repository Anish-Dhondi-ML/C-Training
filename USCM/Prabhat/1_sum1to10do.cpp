// The fifth program in C++ training on 13/02/2023
// sum of first 10 number using do while
#include<iostream>

int main(){
    
    int i=0,sum=0;
    do{
        sum+=i;
        i++;
    }while(i<=10);
    std::cout<<"Sum of first 10 number is : "<<sum<<std::endl;
}
