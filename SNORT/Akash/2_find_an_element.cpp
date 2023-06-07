#include<iostream>
using namespace std;
int main()
{
    char arr[]={'a','e','i','o','u'};

    char ele;
    cout<<"Enter the element to be found: ";
    cin>>ele;
    int n=sizeof(arr)/sizeof(arr[0]);
    int found=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==ele)
        {
            cout<<"The given element is in the position "<<i;
            found=1;
        }
    }
    if(found==0)
        cout<<"Element not found";
}