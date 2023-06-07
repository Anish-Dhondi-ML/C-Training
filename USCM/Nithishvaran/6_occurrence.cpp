#include<iostream>
using namespace std;

int replace(char* str,char c1,char c2,int size){
    for(int i=0;i<size;i++){
        if(*(str+i) == c1)
        {
            *(str+i) = c2;   
        }
    }
}

int main(){

    char str[] = {"nithishvaran"};
    char* ptr = str;
    int size = sizeof(str)/sizeof(char);
    replace(str,'i','a',size);
    for(int i=0;i<size;i++){
        cout<<str[i];
    }
    return 0;
}