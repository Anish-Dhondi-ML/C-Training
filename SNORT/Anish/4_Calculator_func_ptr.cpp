#include<iostream>
#include<stdio.h>

int action(int choice, float a, float b)
{
    float result;
    
    
    switch(choice)
    {
        case 1 : 
            result = a+b;
            std::cout<<"The Summation of given values is : "<<result<<std::endl;
            break;
        case 2 : 
            result = a-b;
            std::cout<<"The Difference of given values is : "<<result<<std::endl;
            break;
        case 3 : 
            result = a*b;
            std::cout<<"The Product of given values is : "<<result<<std::endl;
            break;
        case 4 : 
            result = a/b;
            std::cout<<"The Quotient of given values is : "<<result<<std::endl;
            break;
        
        default :
            std::cout<<"Please give the correct entry. ";
    }
    
    
    return 0;
} 

int main()
{
    int (*ptr)(int ch,float x, float y);
    ptr = action;
    int ch;
    char C;
    float x,y;
    do
    {
    std::cout<<"Enter the Values to perform operation : "<<std::endl;
    std::cin>>x>>y;
    std::cout<<"Enter "<<std::endl<<"1 : Add"<<std::endl<<"2 : Subtract"<<std::endl<<"3 : Multiply"<<std::endl<<"4 : Divide"<<std::endl;
    std::cin>>ch;

    

    (*ptr)(ch,x,y);
    std::cout<<"Do you want to still use the Calculator... (Y/N) ?"<<std::endl;
    std::cin>>C;
    }while (C == 'Y' || C == 'y');

}