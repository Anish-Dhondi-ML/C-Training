// The assignment program in C++ training on 17/02/2023
// This program to find an element or object in a pre defined array
#include<iostream>
#include<array>

int main(){
    
    int arr[10]{12,0,45,29,-21,118,65,-125,33,0};
    int* ptr{&arr[0]};
    //Printing array 1
    std::cout<<"\n Array list :"<<std::endl;
    for (int i{0} ; i<10 ; i++)
        std::cout<<"array["<<i<<"] = "<<*(ptr+i)<<std::endl;
    
    
    int key,index[10]{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},count{-1};
    int* ptr2{&index[0]};
    std::cout<<" Enter Key value to find: ";
    std::cin>>key;
    //searching key in array
    for(int i{0} ; i<10;i++){
        if(key==*(ptr+i)){
            ++count;
            *(ptr2+count)=i;   
        }
    }

    if(count==-1)
        std::cout<<"\n Key doesn't exist in a array";
    else{
        std::cout<<" The Key value found at index : ";
        for(int i{0}; i<=count; i++)
            std::cout<<*(ptr2+i)<<"  ";
    }
    std::cout<<std::endl;
}