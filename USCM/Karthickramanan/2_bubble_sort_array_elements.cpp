#include<iostream>
using namespace std;
int main()
{
 int i,arr[10]={1,2,4,3,66,77,33,45,6,7},j,temp,size;
 size=sizeof(arr)/sizeof(arr[0]);
 for(i=0;i<size;i++)
 {
     for(j=i+1;j<size;j++)
     if(arr[i]>arr[j])
     {
         temp=arr[i];
         arr[i]=arr[j];
         arr[j]=temp;
     }
 }
 for(i=0;i<size;i++)
{
   cout<<arr[i]<<" "; 
}

}
