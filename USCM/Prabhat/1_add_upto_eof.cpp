// The ninth program in C++ training on 13/02/2023
// sum of the user given number untill it gives ono integer or null character

#include<iostream>
int main(){
    // Using while loop
    int i=0,sum=0;
    std::cout<<"Enter the number : ";
    while(std::cin>>i){
        // This loop terminates when we gives the "\0" or "non-integer" as a input
        sum+=i;
        std::cout<<"Enter the number : ";
    }
    std::cout<<"Sum of 10 to 1 number is : "<<sum<<std::endl;
}
