#include<iostream>
using namespace std;

int main(){
    int arr[11]{0},mark;
    cout<<"Enter the marks:"<<endl;
    while(cin>>mark){
        for(int i=0;i<11;i++){
            if(mark<0 || mark>100){
                cout<<"Enter valid data: ";
                break;
            }
            if(mark<10*(i+1) && mark>=10*(i+1)-10)
                arr[i]++;
        }
    }
    for(int i=0;i<10;i++){
        cout<<10*(i+1)-10<<'-'<<10*(i+1)-1<<": "<<arr[i]<<'\t';
    }
    cout<<"100: "<<arr[10];
}