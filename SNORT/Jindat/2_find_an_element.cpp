// Session 2
// 16-02-2023
// Write program to find a element that you can take from keyboard in a array.




#include <iostream>

   
int main(){
    int arr[10], var, i, num;
       
    std::cout << "Enter Number of Elements in an Array" << std::endl;
    std::cin >> var;
     
    std::cout << "Enter " << var << " numbers " << std::endl;
      
    
    for(i = 0; i < var; i++){
        std::cin >> arr[i];
    }
      
    std::cout << "Enter a number to search" << std::endl;
    std::cin >> num;
      
    // search num in inputArray from index 0 to elementCount-1 
    for(i = 0; i < var; i++){
        if(arr[i] == num){
            std::cout << "Element found at index " << i << std::endl;
            break;
        }
    }
      
    if(i == var){
        std::cout  << "Element Not Present in the Array" << std::endl;
    }
 
   
}
