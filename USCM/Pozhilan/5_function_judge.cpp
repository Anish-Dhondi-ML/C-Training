#include<iostream>
using namespace std;

int judge(int *fb(const char *ch)){
    fb(&ch);
}

int function(const char *ch){
    return (int)*ch;
}

int main(){
    const char ch='a';
    cout<<"The integer equivalent of "<<ch<<" is "<<function(&ch)<<endl;
    return 0;
}