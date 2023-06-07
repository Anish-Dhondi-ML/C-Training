#include<iostream>
using namespace std;

int add(int val1,int val2){
    return val1+val2;
}

double add(double val1,double val2){
    return val1+val2;
}

int sub(int val1,int val2){
    return val1-val2;
}

double sub(double val1,double val2){
    return val1-val2;
}

int multiply(int val1,int val2){
    return val1*val2;
}

double multiply(double val1,double val2){
    return val1*val2;
}

int (*intfp[3]) (int,int);
double (*doublefp[3]) (double,double);

int main(){
    intfp[0]=add;
    intfp[1]=sub;
    intfp[2]=multiply;
    doublefp[0]=add;
    doublefp[1]=sub;
    doublefp[2]=multiply;
    int num1,num2;
    double doub1,doub2;
    cout<<"Enter two integers: ";
    cin>>num1>>num2;
    cout<<"Sum: "<<intfp[0](num1,num2)<<"\nDifference: "<<intfp[1](num1,num2)<<"\nProduct: "<<intfp[2](num1,num2);
    cout<<endl<<"Enter two double values: ";
    cin>>doub1>>doub2;
    cout<<"Sum: "<<(*doublefp[0])(doub1,doub2)<<"\nDifference: "<<doublefp[1](doub1,doub2)<<"\nProduct: "<<doublefp[2](doub1,doub2);
    return 0;
}