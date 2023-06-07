#include<iostream>
#include<math.h>
using namespace std;
int main()
{
   int arr[]={1,2,3,4,5},size,i,j,k=0;
   size=sizeof(arr)/sizeof(arr[0]);
   int arr2[size];
   for(i=0;i<size;i++)
   {
       arr2[k]=arr[i];
       k++;
   }
    for(i=0;i<size;i++)
   {
       for(j=i+1;j<size;j++)
       {
           if(arr[i]<arr[j])
           {
               temp=arr[i];
               arr[i]=arr[j];
               arr[j]=temp;
           }
       }
       cout<<arr[i]<<" ";
   }
}
