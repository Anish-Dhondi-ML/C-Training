#include<iostream>

int main()
{   char arr1[3] = {'c','d','e'} 
    int arr[10] = {1,2,3,4,5,6,7,8,9,20};
    char* ptr = &arr1[0];
    char* ptr2 = &arr1[0];
    for(int i {0};i<3;i++)
    {
        std::cout<<" "<<*(ptr+i);
        std::cout<<" "<<*(ptr2+i);
    }
    
}