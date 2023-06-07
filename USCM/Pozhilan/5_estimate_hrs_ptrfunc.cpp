//eg for pointer function 

//eg for real life scenario where external client provides us a function 
//the function is provided by providing address of function in their system



#include<iostream>
using namespace std;

void estimate(int,double (*)(int));
double anand_estimate(int);
double raju_estimate(int);

int main(){
    int codelines=1;
    cout<<"Enter the number of lines in code: ";
    cin>>codelines;
    cout<<"Anand's estimate: "<<endl;
    estimate(codelines, anand_estimate);
    cout<<"Raju's estimate: "<<endl;
    estimate(codelines, raju_estimate);
    return 0;
}

double anand_estimate(int codelines){return 0.05*codelines;}
double raju_estimate(int codelines){return 0.01*codelines;}
void estimate(int codelines, double (*fp)(int)){
    cout<<codelines<<" number of code takes "<<(fp)(codelines)<<" hrs"<<endl;
}