#include<iostream>

double calculate(double,double,double (*)(double,double));

double add(double,double);

double (*addptr[100])(double,double);

double multiply(double,double);

int main(){
    double val1{0.0},val2{0.0};
    int ch=1,i{0};
    std::cout<<"Enter any character to exit. TO CONTINUE PRESS 1"<<std::endl;
    while(std::cin>>ch){
        std::cout<<"_________________________________________"<<std::endl;
        std::cout<<"Enter two decimal values: ";
        std::cin>>val1>>val2;
        addptr[i]=add;
        std::cout<<"The sum of two numbers is "<<calculate(val1,val2,addptr[i])<<std::endl;
        std::cout<<"The product of two numbers is "<<multiply(val1,val2)<<std::endl;
        std::cout<<"_________________________________________"<<std::endl;
        std::cout<<"Enter any character to exit. TO CONTINUE PRESS 1"<<std::endl;
    }
    return 0;
}

double calculate(double a,double b,double (*pf)(double,double)){
    return pf(a,b);
}

double add(double a,double b){
    return a+b;
}

double multiply(double a,double b){
    return a*b;
}