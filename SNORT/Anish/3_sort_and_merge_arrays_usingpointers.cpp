// Session 2
// 16-02-2023
// Write program 2_sort_and_merge_arrays.cpp to to sort 2 pre filled integer arrays and merge them in a 3rd array. 

#include<iostream>

void sort(int *ptr,int n){
    for(int i = 0;i<n;i++){
        for(int j = i;j<n;j++){
            if(*(ptr+i)>*(ptr+j)){ 
                    int temp = *(ptr+i);
                    *(ptr+i) = *(ptr+j);
                    *(ptr+j) = temp;
            }
        }
    }
}


int main(){
    
    int arr1[5] {45,26,58,65,78};
    int* ptr1 = &arr1[0];
    int n1 = sizeof(arr1)/sizeof(int);
    
    int arr2[5] {2,65,142,32,10};
    int* ptr2 = &arr2[0];
    int n2 = sizeof(arr2)/sizeof(int);

    sort((ptr1),n1);
    sort((ptr2),n2);
    
    int arr3[n1+n2];
    int* ptr3 = &arr3[0];

    int i = 0, j = 0, k = 0;
      // traverse the arr1 and insert its element in arr3
      while(i < n1){
      *(ptr3 + k++) = *(ptr1 + i++);
    }
        
      // traverse arr2 and insert in arr3
      while(j < n2){
      *(ptr3 + k++) = *(ptr2 + j++);
    }
        
      // sort the whole array arr3
      sort(ptr3,n1+n2);

      std::cout<<"Array After merging and sorting :"<<std::endl;
    for (int i=0; i < n1+n2; i++)
        std::cout<<*(ptr3 + i)<<" ";
}