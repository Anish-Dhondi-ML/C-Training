#include<iostream>
using namespace std;
int main()
{
    int arr[]={18,100,55,66,22};
    int n=sizeof(arr)/sizeof(arr[0]);
    int temp;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]>arr[j])
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    cout<<"The sorted elements of the given array are: ";
    for(int j=0;j<n;j++)
    {
        cout<<arr[j]<<" ";
    }
}