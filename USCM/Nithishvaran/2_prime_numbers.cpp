#include<iostream>
using namespace std;

int isPrime(int s){

    if(s == 1){
        return 0;
    }else{
         for(int i=2;i<=s/2;i++){
               if(s%i == 0){
                 return 0;
               }
         }
    }
    return 1;
}
int main(){
    
    int a[] = {1,2,3,4,5,6,7,8};
    int count = 0;
    int size = sizeof(a)/sizeof(int);
    for(int i=0;i<size;i++){
        if(isPrime(a[i])){
            count++;
        }
    }
    cout<<"No of prime numbers: "<<count<<endl;
    return 0;
}