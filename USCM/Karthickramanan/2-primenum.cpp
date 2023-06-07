#include<iostream>
#include<math.h>
using namespace std;
int isprime(int s)
{
    if(s == 1)
        return 0;
    else
    {
         for(int i=2;i<=(sqrt(s));i++)
         {
               if(s%i == 0)
                 return 0;
         }
    }
    return 1;
}
int main()
{
    
    int a[] = {2,3,4,6,7};
    int count = 0;
    int size = sizeof(a)/sizeof(a[0]);
    for(int i=0;i<size;i++)
    {
        if(isprime(a[i]))
        {
            count++;
        }
    }
    cout<<"No of prime numbers present: "<<count<<endl;
    return 0;
}
