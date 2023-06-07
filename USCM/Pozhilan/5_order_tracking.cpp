#include<iostream>
#include<string>
using namespace std;


int handleOrderPlacement(int *orderId,string order,int *deldays){
    cout<<"Enter the item to be placed: ";
    cin>>order;
    cout<<"Order placed."<<endl;
    *deldays=5;
    return 1;
}

int handleCancelOrder(int *orderId,string order,int *deldays){
    order="";
    *deldays=0;
    cout<<"Order cancelled"<<endl;
    return 0;
}

int handleRescheduleOrder(int *orderId,string order,int *deldays){
    int ch;
    while(true){
        cout<<"Enter the choice:\n1.Prepone\n2.Postpone\n.......................\n";
        cin>>ch;
        if( ch == 1 || ch == 2 )
            break;
        else
            cout<<"Enter a valid choice"<<endl;
    }
    int val;
    cout<<"Enter no of days: ";
    cin>>val;
    switch(ch){
        case 1: {cout<<"Order preponed to "<<val<<" days"<<endl;
                    *deldays-=val;
        }
        break;
        case 2: {cout<<"Order postponed to "<<val<<" days"<<endl;
                    *deldays+=val;
        }
        break;
    }
    return 1;
}

int handleReceiveOrder(int *orderId,string order,int *deldays){
    cout<<"Your order of "<<order<<"is delivered"<<endl;
    order="";
    *deldays=0;
    return 0;
}

int handleStatusTracker(int *orderId,string order,int *deldays){
    if(*deldays==0 && order==""){
        cout<<"Order delivered."<<endl;
        return 0;
    }
    else if(*deldays>=1){
        cout<<"Order shipped.\nExpected to be delivered in "<<*deldays<<" days."<<endl;
        return 1;
    }
    else if(*deldays==0 & order!=""){
        cout<<"Out for delivery."<<endl;
        return 1;
    }
}

int (*funcPointer[4])(int*,string,int*);


int main(){
    int choice,status{0},orderId,deldays{0};                 //status=0 cart empty 
    string order;       
    funcPointer[0]=handleOrderPlacement;
    funcPointer[1]=handleCancelOrder;
    funcPointer[2]=handleRescheduleOrder;
    funcPointer[3]=handleCancelOrder;
    funcPointer[4]=handleStatusTracker;                               //status=1 shipped,out for delivery
    while(choice){
        if(deldays==0 && status==1){
            status=funcPointer[3](&orderId,order,&deldays);
            choice=0;
        }
        cout<<"Enter your choice:\n1.Place order\n2.Cancel order\n3.Reschedule order\n4.Status tracker"<<endl;
        cin>>choice;
        if(choice==1 && status ==0){
            status=funcPointer[0](&orderId,order,&deldays);
            cout<<"Your order is expected to be delivered in "<<deldays<<" days"<<endl;
        }
        else if(choice==2 && status!=0){
            status=funcPointer[1](&orderId,order,&deldays);
            choice=0;
        }
        else if(choice==3 && status!=0){
            status=funcPointer[2](&orderId,order,&deldays);
            cout<<"Your order is expected to be delivered in "<<deldays<<" days"<<endl;
        }
        else if(choice ==4){
            status=funcPointer[4](&orderId,order,&deldays);
        }
        else{
            cout<<"Enter valid choice"<<endl;
            cout<<"..........................."<<endl;
        }
        int nextdaych{0};
        if(choice){
            cout<<"To move to next day, enter 1: ";
            cin>>nextdaych;
            if(nextdaych==1){
                cout<<"Moving to next day"<<endl;
                deldays--;
            }
        }
    }
}

