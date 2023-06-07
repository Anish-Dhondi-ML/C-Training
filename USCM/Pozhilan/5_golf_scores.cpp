#include<iostream>

int get_input(int arr[]);
void display(int arr[],int);
void calc_avg(int arr[],int);
int main(){
    int array[10],size{0};
    size=get_input(array);
    display(array,size);
    calc_avg(array,size);
    return 0;
}

int get_input(int arr[]){
    std::cout<<"Enter 10 or less golf scores(Press any alphabet to exit)"<<std::endl;
    int i{0};
    for(;i<10 && std::cin>>arr[i];i++);
    return i;
}

void display(int arr[],int size){
    for(int i=0;i<size;i++){
        std::cout<<arr[i]<<'\t';
    }
    std::cout<<std::endl;
}

void calc_avg(int arr[],int size){
    int sum{0};
    for(int i=0;i<size;i++){
        sum+=arr[i];
    }
    std::cout<<"The average of the the score is "<<(double)sum/size<<std::endl;
}
