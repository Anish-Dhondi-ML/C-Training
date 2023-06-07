// The assignment program in C++ training on 20/02/2023
// This program to practice pointer
#include<iostream>
#include<cstdio>

int main(){
    char ch[5][10]{"Apple","MapleLabs","Alice","UCSM"};
    char(*ptr1)[5][10]=&ch;
    char key[]{"MapleLabs"},value[10];
    
    
    for(int i{0}; i<5;i++){
        int flag{0};
       for(int j{0}; j<10; j++){
        if((*ptr1)[i][j]=='\0')
            break;
        else{           
                
                if(key[j]!=(*ptr1)[i][j]){
                    flag=-1;
                    break;
                }
                else flag=1;
            }   
        }
        if(flag==1)
            std::cout<<"Key Matched with index "<<i<<std::endl;
        }              
}