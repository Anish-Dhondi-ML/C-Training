#include<iostream>

int main()
{   
    int i {0};
    char c[4] = {'c','h','a','r'};
    char* ptr = &c[0];
    char d[5] = {'a','c','t','e','r'};
    char* ptr1 = &d[0];
    char e[9] = {};
    char* ptr2 = &e[0];
    while(i<4)
    {
        *(ptr2+i) = *(ptr + i);
        i++;
    }
    i = 0;
    while(i<5)
    {
        *(ptr2+4+i) = *(ptr1 + i);
        i++;
    }
    i = 0;
    while(i<9)
    {
        std::cout<<*(ptr2 + i);
        i++;
    }
}