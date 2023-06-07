#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;

    int arr[n];

    cout<<"Enter the elements : ";
    for(int i=0;i<n;i++)
        cin>>arr[i];

    int count=0;
    int loopvar;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==2 || arr[i]==3)
            count++;

        else
        {
            for(loopvar=2;loopvar<=arr[i]/2;loopvar++)
            {
                if(arr[i]%loopvar==0)
                    break;
            }

            if(loopvar>arr[i]/2)
                count++;
        }
    }

    cout<<"The number of prime numbers in the given array is: "<<count;
}