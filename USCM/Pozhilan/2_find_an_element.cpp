#include<iostream>
using namespace std;

int main(){
    int arr[]{3,9,23,97,65,378,2,1,80,98,136,227,-781,3,-7952,-1,34,-77,-94,3,0},inp,count{0};
    bool found;
    cout<<"Enter the number to be found in array:(To stop execution, press any alphabet key)"<<endl;
    while(cin>>inp){
        cout<<"---"<<endl;
        found=false;
        for(int i=0;i<sizeof(arr)/sizeof(int);i++){
            if(inp==arr[i]){
                count++;
                found=true;
                if(count>1){
                    cout<<", "<<i;
                }
                else
                    cout<<inp<<" found at index "<<i;
            }
        }
        if(found==false)
            cout<<inp<<" is not present in the array";
        cout<<endl;
        count=0;
        cout<<"-------------------------------------------------------------------"<<endl;
    }
    return 0;
}