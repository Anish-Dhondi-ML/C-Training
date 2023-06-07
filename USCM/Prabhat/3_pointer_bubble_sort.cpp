// The assignment program in C++ training on 17/02/2023
// This program to implement bubble sort algorithm on the array by using pointer
#include<iostream>

int main(){
    
    int arr[10]{12,0,45,29,-21,118,65,-125,33,0};
    int* ptr{&arr[0]};
    //Printing array 1
    std::cout<<"\n Unsorted array list :"<<std::endl;
    for (int i{0} ; i<10 ; i++)
        std::cout<<"array["<<i<<"] = "<<*(ptr+i)<<std::endl;
    
    

    for (int i{0}; i< 10-1; i++){ 
        int sorted{-1};
        for (int j{0} ; j < 10-i-1; j++)
            if (*(ptr+j) > *(ptr+j+1)){
                int temp{*(ptr+i)};
                *(ptr+j)=*(ptr+j+1);
                *(ptr+j+1)=temp;
                sorted++;
            }
        if(sorted==-1)
            break;     
    }

    //sorted array
    std::cout<<"\n Sorted array list :"<<std::endl;
    for (int i{0} ; i<10 ; i++)
        std::cout<<"array["<<i<<"] = "<<*(ptr+i)<<std::endl;
}  