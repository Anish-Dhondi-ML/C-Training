// The eighth program in C++ training on 13/02/2023
// The range (intger in the given set of values) 

#include<iostream>
int main(){
    
    int a,b,flag=0;
   
    do{
        std::cout<<"Enter the range : ";
        std::cin>>a>>b;
        if(a!=b){
            flag=0;
            if(a>b){
                std::cout<<"Range between "<<b<<" and "<<a<<"is :"<<std::endl;
                for(int i=b+1;i<a;i++){
                std::cout<<i<<std::endl;
                }
            }
            else{
                std::cout<<"Range between "<<a<<" and "<<b<<" is :"<<std::endl;
                for(int i=a+1;i<b;i++){
                    std::cout<<i<<std::endl;
                } 
            }
        }
        else{
            flag=1;
            std::cerr<<"The both value cannot be a same or zero"<<std::endl;
        }
    }while(flag!=0);
}
