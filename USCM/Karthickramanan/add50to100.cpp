#include<iostream>
using namespace std;
int main()
{
   int a=50,sum=0;
   while(a<=100)
   {
       sum=sum+a;
       a++;
   }
   cout<<sum<<endl;
   sum=0;
   
   a=50;
   for(a=50;a<=100;a++)
   {
       sum=sum+a;
   }
   cout<<sum<<endl;
   a=50,sum=0;
   do{
       sum=sum+a;
       a++;
       
   }
   while(a<=100);
   cout<<sum;
}
