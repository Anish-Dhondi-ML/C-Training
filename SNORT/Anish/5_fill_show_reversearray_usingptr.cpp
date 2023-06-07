// Session 5
// 22-02-2023
// To Fill and Show reverse a given array

#include<iostream>

int main()
{   int n ;
    std::cout<<"Enter the no. of elements required : ";
    std::cin>>n;
    int arr[n] ;
    int* ptr = &arr[0]; 
    
    int i = 0;
    while(i < n)
    {   
        std::cin>>*(ptr+i);
        i++;
    }

     std::cout<<"The original array is : "<<std::endl;
    i = 0;
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