#include<iostream>
using namespace std;

int main(){
    char name[5][10]={"Alcatel","Cisco","Nokia","Siemens","DSC"};
    char (*ptr)[5][10]=&name;
    for(int i=0;i<5;i++){
            cout<<*(*ptr+i)<<'\t';
    }
    return 0;
}