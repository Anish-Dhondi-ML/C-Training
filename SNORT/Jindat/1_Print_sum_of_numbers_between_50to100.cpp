// Session 1
// 13-02-23
// Print sum of numbers between 50 to 100 using forloop , while loop, do-while loop


#include<iostream>


int main(){
    std::cout<<"Using while loop"<<std::endl;
    int i=50;
    int sum=0;

      while(i<=100)
      {
        std::cout<<i<<std::endl;
        sum += i;
        i++;
      }
    std::cout<<"The sum of numbers are : "<<sum<<std::endl;
  
    std::cout<<"Using For loop"<<std::endl;
     sum= 0;
      for(i=50;i <= 100;i++)
      {
        std::cout<<i<<std::endl;
        sum +=i;
      
      }
  std::cout<<"The sum of numbers are : "<<sum<<std::endl;

  std::cout<<"Using Do-While loop"<<std::endl;
     i = 50;
     sum= 0;

     do{
       std::cout<<i<<std::endl;
       sum += i;
       i++;
     }
       while(i<=100);
       {
        std::cout<<"The sum of numbers are : "<<sum<<std::endl;
       }
       
}
