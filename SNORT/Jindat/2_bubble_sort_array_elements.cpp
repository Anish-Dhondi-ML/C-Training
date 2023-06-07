// Session 2
// 15-02-2023
// Write a program to sort an array using Bubble sort technique.


#include<iostream>

int main()
{
    int n, i, arr[10], j, temp;
    std::cout<<"Enter the Size of an array: " << std::endl;
    std::cin>>n;
    
    std::cout<<"Enter the Numbers: " << std::endl;
    for(i=0; i<n; i++)
    {
      std::cin>>arr[i];
    }
        
    std::cout<<"Sorting the Array using Bubble Sort Technique : " << std::endl;
    
    for(i=0; i<(n-1); i++)
    {
        for(j=0; j<(n-i-1); j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    
    
    for(i=0; i<n; i++){
      std::cout << arr[i] << std::endl;
      }
    
}

