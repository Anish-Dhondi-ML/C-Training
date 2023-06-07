// The assignment program in C++ training on 15/02/2023
// This program give max and min value in a pre defined array
#include<iostream>

int main(){
    
    int arr[10]{12,16,45,29,-21,118,65,-125,33,0};
    
    std::cout<<"\n The list of objecta and its value in an array are:"<<std::endl<<std::endl;
    
    for (int i{0} ; i<10 ; i++)
        std::cout<<"array["<<i<<"] = "<<arr[i]<<std::endl;
    /*
    first approach
    // Approach 1st we are holding the value of maximum in max and minimum in min
    int max{arr[0]},min{arr[0]};
    // loop to find max and min
    for(int i{0} ; i<10 ;i++){
        if(max<arr[i])
            max=arr[i];
        if(min>arr[i])
            min=arr[i];
    }
    
    std::cout<<"\n the max value in array is "<<max<<std::endl;
    std::cout<<"\n the max value in array is "<<min<<std::endl;
    */ 

    // Second Approach
    // Approach 2nd we dealing with index value, storing index value of
    //maximum object in max variable and minimum object in min variable
    
    int max{0},min{0};
    // loop to find max and min
    for(int i{0} ; i<10 ;i++){
        if(arr[max]<arr[i])
            max=i;
        if(arr[min]>arr[i])
            min=i;
    }
    
    std::cout<<"\n the maximum value in array is "<<arr[max]<<" at index "<<max<<std::endl;
    std::cout<<"\n the minimum value in array is "<<arr[min]<<" at index "<<min<<std::endl<<std::endl;    
}