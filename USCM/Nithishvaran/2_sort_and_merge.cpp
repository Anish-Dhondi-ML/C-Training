#include<iostream>
using namespace std;

void sort(int a[],int size){
     for(int i=0;i<size;i++){
        for(int j=0;j<size-i-1;j++){
            if(a[j] > a[j+1]){
                swap(a[j],a[j+1]);
            }
        }
    }
}

int main(){

int a[] = {2,5,8,4,9};
int b[] = {1,3,7,0,6};
    
int size_a = sizeof(a)/sizeof(int);
int size_b = sizeof(b)/sizeof(int);

sort(a,size_a);
sort(b,size_b);

int result[size_a+size_b];    
int m=0,p=0;

int i=0;
while(m<size_a && p<size_b){
    if(a[m]<b[p]){
        result[i] = a[m];
        m++;
    }else{
        result[i] = b[p];
        p++;
    }
    i++;
}

if(m>size_a){
    while(p<size_b){
         result[i] = b[p];
         p++;
         i++;
    }
}else{
    while(m<size_a){
        result[i] = a[m];
        m++;
        i++;
    }
}

for(int i=0;i<(size_a+size_b);i++){
        cout<<result[i]<<endl;
}


return 0;
}