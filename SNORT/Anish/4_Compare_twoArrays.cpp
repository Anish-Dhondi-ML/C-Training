#include<iostream>

int main()
{
    int arr1[6] {2,4,6,8,9,0};
    int* ptr1 = &arr1[0];

    int arr2[6] {2,6,3,8,9,10};
    int* ptr2  = &arr2[0];

    int arr3[12];
    int* ptr3 = &arr3[0];

    for(int i{0};i<6;i++)
    {
        for (int j {0};j<6;j++)
        {
            if(*(ptr1 + i) == *(ptr2 + j))
                *(ptr3 + i) = j;
            

        }
    }
    for(int k{0} ; k<5 ; k++)
        std::cout<<" "<<*(ptr3 + k);
}