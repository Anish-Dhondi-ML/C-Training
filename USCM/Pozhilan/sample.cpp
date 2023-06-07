#include<iostream>
#include<string>
using namespace std;

int main(){
    char ch[]={"hello"};
    char (*ptr)[6]=&ch;
    cout<<*ptr<<endl;
    string s="hello all";
    cout<<s;
    s="";
    cout<<s;
   
}