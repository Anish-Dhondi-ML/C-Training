#include<iostream>

int main(){
    int sum=0,i=50;

    while(i<=100)
    {
        sum+=i;
        i++;
    }
    std::cout<<"Sum of numbers 50 to 100 : "<<sum;
}