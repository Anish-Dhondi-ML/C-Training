#include<iostream>
using namespace std;

int fill_array(double doublearr[],int arrsize);
void show_array(double doublearr[],int arrsize);
void reverse_array(double doublearr[],int arrsize);
void special_reverse(double doublearr[],int arrsize);

int main(){
    double doublearr[100];
    int arrsize,choice;
    cout<<"Enter the array size: ";
    cin>>arrsize;
    while(choice){
        cout<<"Enter your choice:\n1.Fill the array\n2.Display array elements\n3.Reverse the array\n4.Special reverse\nEnter any character to stop"<<endl;
        cin>>choice;
        switch(choice){
            case 1: { int noFilled;
                        noFilled= fill_array(doublearr,arrsize);
                        cout<<"The number of elements currently in array are "<<noFilled<<endl;
                    }
                    break;
            case 2: {   cout<<"The array elements are:"<<endl;
                        show_array(doublearr,arrsize);
                    }
                    break;
            case 3: {   reverse_array(doublearr,arrsize);}
                    break;
            case 4: {   special_reverse(doublearr,arrsize);}
                    break;
            default: break;
        }
    }
    return 0;
}

int fill_array(double doublearr[],int arrsize){
    int count{0};
    cout<<"Enter the array elements: "<<endl;
    while(cin>>*(doublearr+count)){
        count++;
        if(count==arrsize)
            break;
    }
    return count;
}

void show_array(double doublearr[],int arrsize){
    for(int i=0;i<arrsize;i++){
        cout<<doublearr[i]<<'\t';
    }
    cout<<endl;
}

void reverse_array(double doublearr[],int arrsize){
    double temp;
    for(int i=0;i<arrsize/2;i++){
        temp=doublearr[i];
        doublearr[i]=doublearr[arrsize-i-1];
        doublearr[arrsize-i-1]=temp;
    }
}

void special_reverse(double doublearr[],int arrsize){
    double temp;
    for(int i=1;i<=(arrsize-2)/2;i++){
        temp=doublearr[i+1];
        doublearr[i]=doublearr[arrsize-i-1];
        doublearr[arrsize-i-1]=temp;
    }
}