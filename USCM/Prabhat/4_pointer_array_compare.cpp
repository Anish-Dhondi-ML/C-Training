// The assignment program in C++ training on 20/02/2023
// This program to practice pointer
#include<iostream>

int main(){
    int n{0};
    std::cout<<"Enter length of both array : ";
    std::cin>>n;
    int arr1[n],arr2[n],cmp[n][3];
    int* ptr1{&arr1[0]}, * ptr2{&arr2[0]};

    std::cout<<"\n Enter the Array 1 of length "<<n<<" :";
    for(int i{0}; i<n; i++){
        std::cin>>*(ptr1+i);
    }

    std::cout<<"\n Enter the Array 2 of length "<<n<<" :";
    for(int i{0}; i<n; i++){
        std::cin>>*(ptr2+i);
    }
    int k{0};
    for(int i{0}; i<n; i++){
        
        for(int j{0}; j<n; j++){
            if(*(ptr1+i)==*(ptr2+j)){
                
                cmp[k][0]=*(ptr1+i);
                cmp[k][1]=i;
                cmp[k][2]=j;
                k++;
            }
        }
    }

    std::cout<<"\n Matched value  index 1   index 2\n";
     for(int i{0}; i<k; i++){
        for(int j{0}; j<3; j++){
            std::cout<<"\t"<<cmp[i][j];            
        }
        std::cout<<"\n";
    }
    
}