// Session 2
// 16-02-2023
/*
Write a program to define an array of 10 ins. Give each element the same value as its posiion in the array. 2_array_index.cpp
Copy the array you created in the prev exercise to another array.
Arrange the array  elements of the prev exercise in descending order
*/ 

#include<iostream>
int main()
{
    int arr[10];
    std::cout<<"Enter the elements in array : "<<std::endl;
    int index;
    int j = 0;
    while(j<10)
    {   
        std::cin>>index;
        if(index>=10){
            std::cout<<"Enter the element btw (0-9) : "<<std::endl;
            std::cin>>index;
            arr[index] = index;
            j++;
            continue;
        }
        if(arr[index] == index){
            std::cout<<"It is already entered try with any other than that : "<<std::endl;
            std::cin>>index;
            arr[index] = index;
            j++;
            continue;
        }
        arr[index] = index;
        j++;
    }
    std::cout<<"The Indexed Array is : "<<std::endl;
    for (int i = 0; i<10;i++)
        std::cout<<" "<<arr[i];

//    Copy the array you created in the prev exercise to another array.

    int arr2[10];
    for (int i = 0; i<10;i++)
        arr2[i] = arr[i];

//    Arrange the array  elements of the prev exercise in descending order

    for(int i = 0;i<10;i++){
    for(int j = i;j<10;j++){
        if(arr[i]<arr[j])
           { int temp = arr2[i];
            arr2[i] = arr2[j];
            arr2[j] = temp;
           }
    }
}
std::cout<<std::endl<<"The Indexed array in Descending Order is : "<<std::endl;
for (int i = 0; i<10;i++)
    std::cout<<" "<<arr2[i];



}