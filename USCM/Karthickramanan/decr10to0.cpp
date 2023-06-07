#include<iostream>
using namespace std;
int main()
{
 int i;
   for(i=10;i>=1;i--)
   {
       cout<<i<<" ";
   }
   cout<<endl;
   i=10;
   while(i)
   {
       cout<<i<<" ";
       i--;
   }
   cout<<endl;
   i=10;
   do{
       cout<<i<<" ";
       i--;
   }
   while(i);
}
