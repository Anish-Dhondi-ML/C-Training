// C++ Program to demonstrate template, on 13/03/2023

#include <iostream>


using namespace std;


template <typename T> class Stack{
    public:
        bool push(T a);
        bool pop();
        bool isEmpty();
        bool isFull();
        Stack();
    
    private:
        enum {max=10};
        T item[max];
        int top;
};

template <typename T> Stack<T>::Stack(){top = -1;}

template <typename T> bool Stack<T>::push(T a){
    if(isFull()){
        cout<<"Stack is full"<<endl;
        return false;
    }
    top++;
    cout<<"The element pushed is : "<<a<<endl;
    
    this->item[top]=a;
    return true;
}

template <typename T> bool Stack<T>::pop(){
    if(isEmpty()){
        cout<<"Stack is Empty"<<endl;
        return false;
    }
    cout<<" Item popped: "<<this->item[top]<<endl;
    
    top--;
    return true;
}

template <typename T> bool Stack<T>::isFull(){
    if(top==max)
        return true;
    else
        return false;
}
template <typename T> bool Stack<T>::isEmpty(){
    if(top==-1)
        return true;
    else
        return false;
}
int main()
{
    Stack<int> a;
    a.push(10);
    a.push(20);
    a.pop();
	
}