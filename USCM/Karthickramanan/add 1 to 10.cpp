#include<iostream>
using namespace std;
int main()
{
   int  i=1,sum=0;
    while(i <= 10)
    {
         sum=sum+i;
         i++;
    }
    cout<<"sum of first 10 numbers is:"<<sum<<endl;
    i=0,sum=0;
    for(int i=0;i<=10;i++)
    {
        sum=sum+i;
    }
    cout<<"sum of first 10 numbers is:"<<sum<<endl;
    i=0;sum=0;
    do{
        sum=sum+i;
        i++;
    }
    while(i<=10);
    
     cout<<"sum of first 10 numbers is:"<<sum;
    

}
