#include <iostream>
using namespace std;

int main()
{
    int a[] = {2,4,1,6,7,8},b[] = {9,7,6,5,4,1};
    int *ptr1 = a;
    int *ptr2 = b;
    int size_a = sizeof(a)/sizeof(int);
    int size_b = sizeof(b)/sizeof(int);

    for(int i=0;i<size_a;i++){
        for(int j=0;j<size_b;j++){
            if(*(ptr1+i) == *(ptr2+j)){
                cout<<"The value "<<*(ptr1+i)<<" of array a "<<i<<endl;
                cout<<"The value "<<*(ptr2+j)<<" of array b "<<j<<endl;
            }
        }
        cout<<endl;
    }
    
    return 0;
}