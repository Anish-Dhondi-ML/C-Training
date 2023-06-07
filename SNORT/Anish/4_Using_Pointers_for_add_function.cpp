#include<iostream>

int (*ptr)(int x, int y);

int add(int a,int b)
{
    return a+b;
}
int main()
{   
   int (*ptr)(int x, int y);

   ptr = add;

   int reslt = (*ptr)(8, 10);
   std::cout<<reslt;
    
}