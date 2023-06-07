#include<iostream>
using namespace std;
int main()
{
  int i,arr[]={1,2,3,4,5,6,7,8,9,10},max,min,j,size;
  max=arr[0],min=arr[0];
  size=sizeof(arr)/sizeof(arr[0]);
  for(i=0;i<size;i++)
      {
          if(arr[i]>max)
          max=arr[i];
          if(arr[i]<min)
          min=arr[i];
      }
  cout<<"max is "<<max<<endl<<"min is "<<min;
}
  
