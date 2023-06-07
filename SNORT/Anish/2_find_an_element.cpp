// Session 2
// 16-02-2023
// Write program 2_find_an_element.cpp to find a element that you can take from keyboard in a pre filled array.

#include<iostream>

int main(){
    int arr[10] {45,26,58,65,78,2,65,142,32,10};
    int n = sizeof(arr)/sizeof(int);
    int item ;
    int flag = 0;
    std::cout<<"Enter the element you want to find : ";
    std::cin>>item;
    for(int i = 0;i<n;i++){
        
        if(item == arr[i]){
            std::cout<<std::endl;
            std::cout<<"The Element "<<item<<" is found in the array at the position : "<<i+1<<std::endl;
            std::cout<<"arr["<<i<<"] = "<<item<<std::endl;
            flag = 1;
            break;
        }    
    }
    if(flag == 0)
        std::cout<<"Element is not Found ! ";

}