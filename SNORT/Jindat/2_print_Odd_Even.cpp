// Session 2
// 14-02-23
// Print the number as even or odd using mathematical operations.


#include<iostream>

int main(){
    int i;
    std::cout << "Enter a number :";
    std::cin >> i;
    
    if(i%2 == 0){
        std::cout <<"The vaue " << i << "is a even number !";
    }
    else{
        std::cout << "The value " << i << " is a odd number !";
    }
}
