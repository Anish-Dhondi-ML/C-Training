#include<iostream>

void estimate(int code_lines, double (*estimate_hrs)(int))
{
    std::cout<<code_lines<<" of code will take "<< (*estimate_hrs)(code_lines)<<" hrs"<<std::endl;
    return;
}
double Anish_estimate(int code){ return (0.01*code);}
double Dhondi_estimate(int code){ return (0.05*code);}
int main()
{
    int code_lines = 1;
    std::cout<<"How many lines of code the program has : ";
    std::cin>>code_lines;
    std::cout<<" This is Anish's estimate hrs he takes to type the code : "<<std::endl;
    estimate(code_lines,Anish_estimate);
    std::cout<<" This is Dhondi's estimate hrs he takes to type the code : "<<std::endl;
    estimate(code_lines,Dhondi_estimate);

}