#include <iostream>
using namespace std;
 
int * fun(int* ptr) { 
    for(int i=1;i<=9;i++){
      *(ptr+i) = i;
    }
   return ptr;
 }
 
// Driver code
int main()
{
    int x[10] = {1,2,3,4,5,6,7,8,9};
    int* ptr = x;
    int * ptr1 = fun(ptr);
    for(int i=0;i<9;i++){
        cout<<*(ptr1+i)<<endl;
    }
    return 0;
}