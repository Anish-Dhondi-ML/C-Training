#include<iostream>
using namespace std;

int main(){
    int a=5,*ptr1=&a;
    *ptr1+=5;
    cout<<*ptr1;
}