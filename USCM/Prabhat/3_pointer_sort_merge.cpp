// The assignment program in C++ training on 17/02/2023
// This program to implement sort and merge algorithm on the array using pointer
#include<iostream>

int main(){
    
    int arr1[10]{12,16,45,29,-21,118,65,-125,33,0};
    int arr2[5]{38,19,-23,-44,83};
    int* ptr1{&arr1[0]},* ptr2{&arr2[0]};
    //Printing array 2
    std::cout<<"\n Array list 1 :"<<std::endl;
    for (int i{0} ; i<10 ; i++)
        std::cout<<"array["<<i<<"] = "<<*(ptr1+i)<<std::endl;
    
    // Printing Array 1
    std::cout<<"\n Array list 2 :"<<std::endl;
    for (int i{0} ; i<5 ; i++)
        std::cout<<"array["<<i<<"] = "<<*(ptr2+i)<<std::endl;
    
    //Merging in Array 3
    int arr3[15];
    int* ptr3{&arr3[0]};
    for(int i{0} ; i<15;i++){
        if(i<=9)
            *(ptr3+i)=*(ptr1+i);
        else
            *(ptr3+i)=*(ptr2+i-10);
    }

    //Printing Array 3
    std::cout<<"\n Array list 3 :"<<std::endl;
    for (int i{0} ; i<15 ; i++)
        std::cout<<"array["<<i<<"] = "<<*(ptr3+i)<<std::endl;
    
    //Sorting the array 3
    
   for(int i{0} ; i<15; i++ ){
        for(int j{i} ; j<15 ; j++){
            if(*(ptr3+i)>*(ptr3+j)){ 
                    int temp{*(ptr3+i)};
                    *(ptr3+i) = *(ptr3+j);
                    *(ptr3+j) = temp;
            }
        }
    }
    //Sorted array 
    std::cout<<"\n Sorted Array list 3 :"<<std::endl;
    for (int i{0} ; i<15 ; i++)
        std::cout<<"array["<<i<<"] = "<<(ptr3+i)<<std::endl;
}