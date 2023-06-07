#include <iostream>
using namespace std;
int sort(int a[],int n)
{
    int i,j,t;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            {
                t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
        }
    }
}
int main()
{
    int n=5;
    int a[]={5,5,54,2,1},b[]={7,9,3,11,6},i,k=0,j,asize,bsize;
    asize=sizeof(a)/sizeof(a[0]);
    bsize=sizeof(b)/sizeof(b[0]);
    int csize=asize+bsize;
    int c[10];
    sort(a,n);
    sort(b,n);
    for(i=0;i<asize;i++)
    {
      c[k]=a[i];
      k++;
    }
    for(j=0;j<bsize;j++)
    {
        c[k]=b[j];
        k++;
    }
    for(i=0;i<asize+bsize;i++)
    {
        cout<<c[i]<<" ";
    }
    return 0;
}


