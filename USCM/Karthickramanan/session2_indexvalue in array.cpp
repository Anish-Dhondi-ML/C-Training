#include<iostream>
using namespace std;
int main()
{
  int i,n;
  cin>>n;
  int arr[n];
  for(i=0;i<n;i++)
  {
      arr[i]=i+1;
  }
  for(i=0;i<n;i++)
  cout<<arr[i]<<" ";
}
