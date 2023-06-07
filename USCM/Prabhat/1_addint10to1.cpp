// The seventh program in C++ training on 13/02/2023
// sum of first 10 number in reverse order using while, for and do-while loop

#include<iostream>
int main(){
    // Using while loop
    int i=10,sum=0;
    while(i>=1){
        sum+=i;
        i--;
    }
    std::cout<<"Sum of 10 to 1 number is : "<<sum<<std::endl;
    
    // Using for loop
    sum=0;
    for(int j=10;j>=1;j--){
        sum+=j;
    }
    std::cout<<"Sum of 10 to 1 number is : "<<sum<<std::endl;
    
    // Using do-while loop
    i=10;
    sum=0;
    do{
        sum+=i;
        i--;
    }  while(i>=1);  
    std::cout<<"Sum of 10 to 1 number is : "<<sum<<std::endl;
}
