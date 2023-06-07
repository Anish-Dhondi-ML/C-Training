#include<iostream>
using namespace std;

int main(){
    int low_limit,high_limit;
    cout<<"Enter two integers: ";
    cin>>low_limit>>high_limit;
    if(low_limit>high_limit)
    {
        low_limit+=high_limit;
        high_limit=low_limit-high_limit;
        low_limit=low_limit-high_limit;
    }
    cout<<"The numbers between the limit are"<<endl;
    cout<<"------------------------------------------"<<endl;
    cout<<"------------------------------------------"<<endl<<"For loop:"<<endl;
    //for loop operation
    for(int i=low_limit;i<=high_limit;i++){
        cout<<i<<'\t';
    }
    cout<<endl<<"------------------------------------------"<<endl<<"do-while loop:"<<endl;
    //do-while operation
    int i=low_limit;
    do{
        cout<<i++<<'\t';
    }while(i<=high_limit);
    cout<<endl<<"------------------------------------------"<<endl<<"while loop:"<<endl;
    //while operation
    i=low_limit;
    while(i<=high_limit){
        cout<<i++<<'\t';
    }
     return 0;
}