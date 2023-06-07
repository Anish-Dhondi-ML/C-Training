#include<iostream>
#include<string>
#include <windows.h>
using namespace std;

int products[] = {100,150,200,120,60,40,20};
int cart[7];

enum Status {OrderDisplayed,Prdt_added_to_cart,Payment_Done,Shipment_success,Cancel_Order,Order_Deliveried};

int handleorder(int size){

cout<<"List of products available"<<endl;
for(int i=0;i<size;i++){
  cout<<"Product - "<<" "<<i<<" = "<<products[i]<<endl;
}

return 0;

}

int handlecart(int itemno){

static int j=0;
if(itemno <= 7){
  cart[j] = itemno;
  j++;
}else{
  cout<<"Cart empty"<<endl;
}

return j;
}

int handlepayment(int no_of_items){

int sum = 0;
for(int i=0;i<no_of_items;i++){
  sum+=products[cart[i]];
}

return sum;
}



int main(){

    int (*operations[6])(int) = {handleorder,handlecart,handlepayment};
    int size = sizeof(products)/sizeof(int);
    (*operations[0])(size);
    cout<<"Enter 8 to move to payments"<<endl;
    cout<<endl;
    int total_no_items = 0;
    int total_cost = 0;
    
    Status state = OrderDisplayed;

    while(true){
        cout<<"Enter product no: "<<endl;
        int p_no=0;
        cin>>p_no;
        if(p_no != 8){
          total_no_items = (*operations[1])(p_no); 
        }else{
          break;
        }
    }
    
    if(total_no_items > 0){

      state = Prdt_added_to_cart;
      total_cost = (*operations[1])(total_no_items);

      if(total_cost > 0){
         state = Payment_Done;
         cout<<"Order Summary"<<endl;
         
         for(int i=0;i<total_no_items;i++){
            cout<<"Product - "<<cart[i]<<" = "<<products[cart[i]]<<endl;
         }
      }

    }

    if(state == Payment_Done){

      cout<<"Payment Success Preparing for shipment"<<endl;
      Sleep(5000);
      state = Shipment_success;
      cout<<endl;
      cout<<"Product Shipped Successfully"<<endl;
      cout<<endl;
      cout<<"If you want to cancel Order enter 1 or else 2"<<endl;
      int s=0;
      cin>>s;
        if(s == 1){
            state = Cancel_Order;
        }else{

        }

    }else{
        cout<<"Payment Failed"<<endl;
    }

    

    if(state == Cancel_Order){
        cout<<"Your Order is Cancelled Successfully Refund process is initiated"<<endl;
    }
    else{
        cout<<"Order Delivered";
    }
   
    return 0;
}