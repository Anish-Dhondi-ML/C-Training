// Session 1
// 13-02-2023
// Eof prgm


#include<iostream>

int main()
{
    int i = 0;
    int sum = 0;
    std::cout<<"Enter the no. : "<<std::endl;
    while(std::cin>>i)
    {
        sum += i;
        std::cout<<"Enter the no. :"<<std::endl;

        // loop terminates when a non integer value or null value is inserted

    }
    std::cout<<"The sum is : "<<sum<<std::endl;
    return 0 ;

}