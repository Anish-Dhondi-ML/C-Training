// Session 2
// 16-02-2023
// To reverse a given array

#include<iostream>

int main()
{
    int arr[10] {12,23,34,5,6,74,23,4,5,123};
    int* ptr = &arr[0]; 
    int n = sizeof(arr)/sizeof(int);

     std::cout<<"The original array is : "<<std::endl;
    int i {0};
    while(i < n)
    {
        std::cout<<" "<<*(ptr+i);
        i++;
    }

    int f{0};
    int b{n-1};

    while(f<b)
    {
        std::swap(*(ptr+f),*(ptr+b));
        f++;
        b--;
    }
    std::cout<<std::endl;
    std::cout<<"The reversed array is : "<<std::endl;
    i = 0;
    while(i < n)
    {
        std::cout<<" "<<*(ptr+i);
        i++;
    }
}