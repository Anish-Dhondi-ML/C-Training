#include<iostream>
using namespace std;
int main()
{
    int arr[]={27,11,89,43,24};
    int n=sizeof(arr)/sizeof(arr[0]);
    int max=arr[0];
    int min=arr[0];
    for(int i=0;i<n;i++)
    {
            if(max==arr[i])
                continue;

            else if(max<arr[i])
                max=arr[i];
    }

    for(int i=0;i<n;i++)
    {
            if(min==arr[i])
                continue;

            else if(min>arr[i])
                min=arr[i];
    }
    cout<<"The largest and the smallest of the pre-filled array are "<<max<< " and "<<min<<" respectively";
}