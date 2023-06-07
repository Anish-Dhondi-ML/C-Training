#include<iostream>
#include<string>
using namespace std;

void count_and_print(string s){
    int static count;
    if(s!="")
        cout<<count++<<". "<<s<<endl;
}

int main(){
    count_and_print("");
    count_and_print("hello");
    count_and_print("hi and welcome");
    count_and_print("This is new");
    return 0; 
}