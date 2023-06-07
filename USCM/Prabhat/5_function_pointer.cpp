// The assignment program in C++ training on 22/02/2023
// This program to practice function
#include<iostream>

void add(int a, int b)
{
    std::cout<<"Addition is :"<<a+b<<"\n";
}
void (*add_ptr)(int,int)=&add;

void subtract(int a, int b)
{
    std::cout<<"Subtraction is :"<<a-b<<"\n";
}
void (*subtract_ptr)(int,int)=&subtract;

void multiply(int a, int b)
{
    std::cout<<"Multiplication is :"<<a*b<<"\n";
}
void (*multiply_ptr)(int,int)=&multiply;  
int main(){
    
    do{
        int choice(1);
        std::cout<<" 1. Add\n 2. Subtract \n 3. Multiply\n 0. Exit \n";
        std::cout<<" Enter Your choice :";
        std::cin>>choice;
        int a,b;
        switch(choice){
            case 0: exit(1);
            case 1: 
                    std::cout<<" Enter two number :";
                    std::cin>>a>>b;
                    (*add_ptr)(a,b);
                    break;
            case 2: 
                    std::cout<<" Enter two number :";
                    std::cin>>a>>b;
                    (*subtract_ptr)(a,b);
                    break;
            case 3: 
                    std::cout<<" Enter two number :";
                    std::cin>>a>>b;
                    (*multiply_ptr)(a,b);
                    break;
            default :std::cout<<" Wrong Choice \n";
        }
    }while (true);
        
}