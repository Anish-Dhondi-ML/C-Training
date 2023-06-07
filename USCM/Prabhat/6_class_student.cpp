// The assignment program in C++ training on 27/02/2023
// This program to practice enum
#include<iostream>
#include<cstdio>

class Student{
    private: 
        float percentage;
        bool result=result(percentage);
    protected:
        int sub=5;
        bool result(double x){
            if(x>33.0)
                return 1;
            else
                return 0;
        }
    public:
        int marks[sub];   
        char name[20];
        void getdata(){
            std::cout<<"Enter name: ";
            std::cin>>name;
            std::cout<<"No of subject is ";
            std::cin>>sub;
            
        }
};

int main(){
    char ch;

    int a=10;    
    std::cout<<ch<<std::endl;
}