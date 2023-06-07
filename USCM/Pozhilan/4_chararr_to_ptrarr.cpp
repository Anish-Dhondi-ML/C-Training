#include<iostream>
#include<cstring>
using namespace std;

int main(){
    char str[5][11]={"alcatel","nokia","siemmens","maple labs","sound"};
    char (*ptr)[11]=str;
    bool found=false;
    for(int i=0;i<5;i++){
        if(strcmp(*(ptr+i),"maple labs")==0){
            cout<<"Element found"<<endl;
            found=true;
        }
        cout<<"*ptr+i "<<**ptr+i<<endl;
        cout<<"*(ptr+i) "<<(ptr+i)<<endl;
    }
    if(!found)
        cout<<"Element not found";
    for(int i=0;i<5;i++)
        cout<<*(ptr+i)<<'\t';
    return 0;
}