#include<iostream>
#include<string.h>

void count_print(std::string s);
int main()
{   count_print("");
    count_print("Hello");
    count_print("Here Iam");
}
void count_print(std::string s)
{
    static int count;
    std::cout<<count++<<"."<<s<<std::endl;
}