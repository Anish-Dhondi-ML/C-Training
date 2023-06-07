#include<iostream>
using namespace std;

int main()
{
    int arr1[]={85,32,74,67,12};
    int arr2[]={90,22,19,49,109};
    int mergedarr[10];
    int n1=sizeof(arr1)/sizeof(arr1[0]);
    int n2=sizeof(arr2)/sizeof(arr2[0]);

    for(int i=0;i<n1;i++)
        mergedarr[i]=arr1[i];

    int index=n1;

    for(int j=0;j<n2;j++)
    {
        mergedarr[index]=arr2[j];
        index++;
    }

    int n3=sizeof(mergedarr)/sizeof(mergedarr[0]);
    for(int k=0;k<n3;k++)
    {
        for(int l=k+1;l<n3;l++)
        {
            if(mergedarr[k]>mergedarr[l])
            {
                int temp=mergedarr[k];
                mergedarr[k]=mergedarr[l];
                mergedarr[l]=temp;
            }
        }
    }

    cout<<"The sorted elements of the merged array are: ";
    for(int m=0;m<n3;m++)
        cout<<mergedarr[m]<<" ";
}