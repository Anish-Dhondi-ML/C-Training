// Session 2
// 15-02-2023
// Bubble sorting the Array



#include<iostream>

int main(){
    int n;

std::cout<<"Enter the no. elements required in the array : ";
std::cin>>n;
if(n==0)
    {std::cout<<"Give n should not be zero give another value :";
    std::cin>>n;
    }
int arr[n] ;
std::cout<<"Enter the elements in the array : "<<std::endl;
for (int i = 0; i<n;i++)
    std::cin>>arr[i]; 
std::cout<<"The Unsorted array is : "<<std::endl;
for (int i = 0; i<n;i++)
    std::cout<<" "<<arr[i];

for(int i = 0;i<n;i++){
    for(int j = i;j<n;j++){
        if(arr[i]>arr[j])
           { int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
           }
    }
}
std::cout<<std::endl<<"The Sorted array is : "<<std::endl;
for (int i = 0; i<n;i++)
    std::cout<<" "<<arr[i];


}
