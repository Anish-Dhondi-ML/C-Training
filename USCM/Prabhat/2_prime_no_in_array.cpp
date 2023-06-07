// The assignment program in C++ training on 15/02/2023
// This program to find prime number in array
#include<iostream>

int main(){
    
    int arr[10]{12,2,1,29,-21,7,65,-125,33,0};
   
    //Printing array 1
    std::cout<<"\n Unsorted array list :"<<std::endl;
    for (int i{0} ; i<10 ; i++)
        std::cout<<"array["<<i<<"] = "<<arr[i]<<std::endl;
    
    int count{0};

    for(int i{0} ; i<10; i++){
        int n{arr[i]};
        if(n>1){
            for (int j{2}; j <= n/2; j++) {
                if (n % j == 0){
                    count++;
                    break;
                }
            }   
        }
        else
            count++;
    }

    // Total no. of prime number in array
    std::cout<<"\n Total Prime number in an array is: "<<10-count<<std::endl;
    
} 