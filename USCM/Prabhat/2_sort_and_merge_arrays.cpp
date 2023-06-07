// The assignment program in C++ training on 15/02/2023
// This program sort the array and merge them
#include<iostream>

int main(){
    
    int arr1[10]{12,16,45,29,-21,118,65,-125,33,0};
    int arr2[5]{38,19,-23,-44,83};

    //Printing array 2
    std::cout<<"\n Array list 1 :"<<std::endl;
    for (int i{0} ; i<10 ; i++)
        std::cout<<"array["<<i<<"] = "<<arr1[i]<<std::endl;
    
    // Printing Array 1
    std::cout<<"\n Array list 2 :"<<std::endl;
    for (int i{0} ; i<5 ; i++)
        std::cout<<"array["<<i<<"] = "<<arr2[i]<<std::endl;
    
    //Merging in Array 3
    int arr3[15];
    for(int i{0} ; i<15;i++){
        if(i<=9)
            arr3[i]=arr1[i];
        else
            arr3[i]=arr2[i-10];
    }

    //Printing Array 3
    std::cout<<"\n Array list 3 :"<<std::endl;
    for (int i{0} ; i<15 ; i++)
        std::cout<<"array["<<i<<"] = "<<arr3[i]<<std::endl;
    
    //Sorting the array 3
   for(int i{0} ; i<15; i++ ){
        for(int j{i} ; j<15 ; j++){
            if(arr3[i]>arr3[j]){ 
                    int temp{arr3[i]};
                    arr3[i] = arr3[j];
                    arr3[j] = temp;
            }
        }
    }
    //Sorted array 
    std::cout<<"\n Array list 3 :"<<std::endl;
    for (int i{0} ; i<15 ; i++)
        std::cout<<"array["<<i<<"] = "<<arr3[i]<<std::endl;
}