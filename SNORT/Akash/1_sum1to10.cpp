#include<iostream>

int main(){
    int sum=0,i=1;

    while(i<=10)
    {
        sum+=i;
        i++;
    }
    std::cout<<"Sum of numbers 1 to 10 : "<<sum;
}