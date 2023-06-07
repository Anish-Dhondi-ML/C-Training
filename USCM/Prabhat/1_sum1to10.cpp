// The third program in C++ training on 13/02/2023
// sum of first 10 number using while
#include<iostream>

int main(){
    
    int i=0,sum=0;
    while(i<=10){
        sum+=i;
        i++;
    }
    std::cout<<"Sum of first 10 number is : "<<sum<<std::endl;
}
