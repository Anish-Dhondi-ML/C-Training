// The assignment program in C++ training on 21/02/2023
// This program to practice function
#include<iostream>
#include<cstdio>
void swapr(int &, int &);
void swapp(int *, int *);
void swap(int,int);
int main(){
    
    int j=10,k=25;
    swap(j,k);
    std::cout<<j<<"\t"<<k<<std::endl;
    swap(j,k);
    swapr(j,k);
    std::cout<<j<<"\t"<<k<<std::endl;
    swap(j,k);
    swapp(&j,&k);
    std::cout<<j<<"\t"<<k<<std::endl;
}

void swapr( int &a, int &b){
    
    int temp=a;
    a=b;
    b=temp;
}

void swapp( int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void swap( int a, int b){
    static int count;
    std::cout<<count++<<" Swap function called\n";
    int temp=a;
    a=b;
    b=temp;
}