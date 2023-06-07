#include<iostream>
using namespace std;

int replace(char *str,char c1, char c2);

int main(){
    char str[100];          //original string where replacing would be done
    cout<<"Enter a string: ";
    cin.getline(str,100,'\n');
    char c1,c2;
    cout<<"Enter the character that needs to be replaced: ";
    cin>>c1;
    cout<<"Enter the replacing character: ";
    cin>>c2;
    int numOfReplacements=replace(str,c1,c2);
    cout<<"The number of times replacements done are: "<<numOfReplacements<<endl;
    cout<<"The reframed string is: \""<<str<<"\""<<endl;
    return 0;
}

int replace(char *str, char c1, char c2){
    int countReplacement{0};
    for(int i=0;*(str+i)!='\0';i++){
        if(*(str+i)==c1){
            *(str+i)= c2;
            countReplacement++;
        }
    }
    return countReplacement;
}