#include<iostream>
using namespace std;
int main()
{
    int arr[10];
    for(int i=0;i<10;i++)
        arr[i]=i;

    cout<<"Printing the elements of the array..."<<endl;

    for(int i=0;i<10;i++)
        cout<<arr[i]<<" ";

    cout<<endl;
    int copy[10];

    for(int j=0;j<10;j++)
        copy[j]=arr[j];

    cout<<"Printing the elements of the array copy..."<<endl;

    for(int j=0;j<10;j++)
        cout<<copy[j]<<" ";
    cout<<endl;

    cout<<"Sorting the array..."<<endl;
    for(int k=0;k<10;k++)
    {
        for(int j=k+1;j<10;j++)
        {
            if(copy[k]<copy[j])
            {
                int temp=copy[k];
                copy[k]=copy[j];
                copy[j]=temp;
            }
        }
    }

    cout<<"Printing the elements of the sorted array copy..."<<endl;
    for(int j=0;j<10;j++)
        cout<<copy[j]<<" ";
}