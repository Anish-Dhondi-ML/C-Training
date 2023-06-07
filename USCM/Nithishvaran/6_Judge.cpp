#include<iostream>
using namespace std;


int ASCII(const char c){
      return (int)c;
}
int judge(const char c,int (*fun)(const char)){
    return (*fun)(c);
}

int main(){
  const char c = 'a';
  cout<<judge(c,ASCII);
    return 0;
}