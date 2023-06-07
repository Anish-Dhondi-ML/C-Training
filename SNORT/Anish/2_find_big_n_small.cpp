// Session 2
// 16-02-2023
// Write program 2_find_big_n_small.cpp to to find biggest and smallest element in the pre filled array. 


#include<iostream>

int main(){
    int arr[10] {45,26,58,65,78,2,65,142,32,10};
    int n = sizeof(arr)/sizeof(int);
    int max = arr[0];
    int min = arr[0];
    std::cout<<"Elements in the array are : "<<std::endl;
    for(int i = 0;i<n;i++){
        std::cout<<" "<<arr[i];
        if(max<arr[i])
            max = arr[i];
        if(min>arr[i])
            min = arr[i];
    }
    std::cout<<std::endl;
    std::cout<<"The Largest element in the array : "<<max<<std::endl;
    std::cout<<"The Smallest element in the array : "<<min<<std::endl;
}

