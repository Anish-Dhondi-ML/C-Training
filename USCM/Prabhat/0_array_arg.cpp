// The practice program on 23/02/2023
// This program to practice function pointer
#include<iostream>
void double_(int* a, int size){
    for(int i=0; i<size; i++)
        a[i]=a[i]*2;
}

int main(){
    int p[]={1,2,3,4,5};
    int size = sizeof(p)/sizeof(p[0]);
    double_(p,size);
    for(int i=0; i<size; i++)
        std::cout<<p[i]<<"\n";
    
    char ch[]="hello";
    char* cp;
    cp=ch;
    std::cout<<cp[1]<<std::endl;

    int i, &ri = i;
    i = 5; ri = 10;
    std::cout << i << " " << ri << std::endl;
}