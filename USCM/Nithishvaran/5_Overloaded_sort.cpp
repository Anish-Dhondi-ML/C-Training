#include<iostream>
using namespace std;

void sort(int *a,int n){ // Overloaded sort function to sort the array of interger varibales

    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(*(a+j) > *(a+(j+1))){
                swap(*(a+j), *(a+(j+1)));
            }
        }
    }
}

void sort(double *a,int n){ // Overloaded sort fuction to sort the array of double variables

    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(*(a+j) > *(a+(j+1))){
                swap(*(a+j), *(a+(j+1)));
            }
        }
    }
}

void sort(char *a,int n){ //  Overloaded fuction to sort the array of charecter variables

    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(*(a+j) > *(a+(j+1))){
                swap(*(a+j), *(a+(j+1)));
            }
        }
    }
}

int main(){


    int name=0;
    int a[] = {3,2,6,9,7};
    double b[] = {3.3,5.3,1.1,5.2,1.2};
    char c[] = {'d','e','f','a','b'}; 
    sort(a,5);
    for(int i=0;i<5;i++){
        cout<<a[i]<<endl;
    }

    sort(b,5);
    for(int i=0;i<5;i++){
        cout<<b[i]<<endl;
    }

    sort(c,5);
    for(int i=0;i<5;i++){
        cout<<c[i]<<endl;
    }
    return 0;
}