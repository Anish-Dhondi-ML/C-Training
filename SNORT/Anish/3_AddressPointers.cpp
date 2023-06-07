#include<iostream>

int main()
{
    int i = 60 ;
    char j = 'c' ; 
    std::cout<<&i<<std::endl;

    int* ptr = &i;
    char* ptr2 = &j;

    
    std::cout<<*ptr<<std::endl; // gives the value *ptr
    std::cout<<ptr<<std::endl;  // gives the address
    std::cout<<sizeof(ptr)<<std::endl;
    std::cout<<sizeof(ptr2)<<std::endl;
    
    std::cout<<std::endl;
 





}