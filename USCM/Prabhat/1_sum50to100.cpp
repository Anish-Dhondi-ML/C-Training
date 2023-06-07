// The sixth program in C++ training on 13/02/2023
// sum of 50 to 100 number using while, do-while and for loop
#include<iostream>

int main(){
    
    //Using while loop
    int i=50,sum=0;
    while(i<=100){
        sum+=i;
        i++;
    }
    std::cout<<"Sum of 50 to 100 number is : "<<sum<<std::endl;

    //Using for loop
    sum=0;
    for(int j=100;j>=50;j--){
        sum+=j;
    }
    std::cout<<"Sum of 50 to 100 in reverse order number is : "<<sum<<std::endl;
    
    //Using do-while loop
    i=100;
    sum=0;
    do{
        sum+=i;
        i--;
    }  while(i>=50);  
    std::cout<<"Sum of 50 to 100 in reverse order number is : "<<sum<<std::endl;
}
