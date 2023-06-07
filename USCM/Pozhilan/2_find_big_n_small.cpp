#include<iostream>
using namespace std;

int main(){
    int intArr[]{56,89,23,678,24,51,33,65,24,65,24,907,45,243,0,-35,-947,67,0}, max{0},min{0};
    for(int i=0;i<(sizeof(intArr))/(sizeof(int));i++){
        if(max<intArr[i])
            max=intArr[i];
        else if(min>intArr[i]){
            min=intArr[i];
        }
    }
    cout<<"Maximum value in array: "<<max<<endl<<"Minimum value in array: "<<min;
    return 0;
}