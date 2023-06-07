#include<iostream>
#include<fstream>
using namespace std;

int main(){
    int inp;
    char choice;
    ofstream fout("c:/integerread.txt");
    cout<<"Enter the integers:(Press any non-integer value to exit)"<<endl;
    while(cin>>inp){
            fout<<inp<<'\t';
    }
    fout.close();
    cout<<"The given input are: ";
    ifstream fin("c:/integerread.txt");
    while(fin>>inp){
        cout<<inp<<'\t';
    }
    fin.close();
    return 0;
}