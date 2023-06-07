#include<iostream>
using namespace std;

void swap(int u,int l);
void swapr(int &u,int &l);
int main(){
    int a{5},b{3};
    cout<<"Before swap: "<<endl<<a<<'\t'<<b<<endl;
    swap(a,b);
    cout<<"After swap: "<<endl<<a<<'\t'<<b<<endl;
    int& refa=a;
    int& refb=b;
    swapr(refa,refb);
    cout<<"After reference swap: "<<endl<<a<<'\t'<<b;
    return 0;
}

void swapr(int &u,int &l){
    int &t=u;
    u=l;
    l=t;
    cout<<"Inside reference swap function:\n"<<"u="<<u<<" and l="<<l<<endl;
    return ;
}

void swap(int u,int l){
    int t;
    t=u;
    u=l;
    l=t;
    return ;
}