#include<iostream>
using namespace std;

int main(){
    char ch[][10]={"wanna","hanna","moana","gonna"};
    char *ptr[5]={&ch[0][10],&ch[1][10],&ch[2][10],&ch[3][10]};
    for(int i=0;i<4;i++){
        cout<<*(ptr+i)<<'\t';
    }
    return 0;
}