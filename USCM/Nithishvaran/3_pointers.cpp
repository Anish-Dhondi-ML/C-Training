#include <iostream>
using namespace std;

int main()
{

    // Sorting an given array

    int a[] = {3,2,6,1,8,9};
    int* ptr = &a[0];
    int size = sizeof(a)/sizeof(int);

    for(int i=0;i<size;i++){
        for(int j=0;j<size-i-1;j++){
            if(*(ptr+j) > *(ptr+j + 1)){
                swap(*(ptr+j),*(ptr+j + 1));
            }
        }
    }

    for(int i=0;i<size;i++){
        cout<<*(ptr+i)<<endl;
    }


    // Find the position of the element in an given array

    char b[] = {'n','i','t','h','i','s','h'};

    char* ptr1 = &b[0];
    int size1 = sizeof(b)/sizeof(char);

    for(int i=0;i<size1;i++){
        if(*ptr1 == 'h'){
            cout<<"'H' holds position: "<<i<<endl;
        }
        ptr1++;
    }
    
    // Copying one pointer variable  to another pointer variable

    int *ptr3 = ptr;

    for(int i=0;i<size;i++){
        cout<<*(ptr3+i)<<endl;
    }

    // Changing the value of one element 

    *(ptr3+2) = 5;
    cout<<"The Updated array elements: "<<endl;
    for(int i=0;i<size;i++){
        cout<<*(ptr+i)<<endl;
    }

    return 0;
}