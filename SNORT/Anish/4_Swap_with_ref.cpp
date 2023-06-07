#include<iostream>


void swapr(int &, int &);
void swapp(int *, int *);
void swap(int,int);

int main(){
    int j=5,k=10;
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