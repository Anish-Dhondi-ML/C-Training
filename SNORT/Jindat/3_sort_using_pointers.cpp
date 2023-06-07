//Session 3
//17-02-2023
//Write a program to sort an array uisng pointers and print the address of the pointer.




#include<iostream>

int main(){
  int arr[5];
  int* p = arr;

  std::cout<< "Enter elements in an array " << std::endl;
  for(int i=0 ; i<5 ; i++)
    {
      std::cin >> *(p+i);
    }

  for(int i=0; i<5 ; i++)
    {
      for(int j=0; j<(5-i-1) ; j++)
        {
          if(*(p+j) > *(p+(j+1)))
          {
            int t = *(p+j);
            *(p+j) = *(p+(j+1));
            *(p+(j+1)) = t;
          }
        }
    }
  std::cout << "Array after sorting : " << std::endl;

  for(int i=0 ; i<5 ; i++)
    {
      std::cout << *(p+i) << " " << std::endl;
    }
  std::cout << "Address of the var : " << &*(p) << std::endl;
}
