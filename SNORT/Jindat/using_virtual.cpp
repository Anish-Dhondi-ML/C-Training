//08/03/2023
//Virtual.

#include<iostream>
using namespace std;

class animal{
public:  virtual void makessound();
};

class Dog:public animal{
public:
      virtual void makessound();

};

class Cat:public Dog{
public:
        virtual void makessound();

};

void animal::makessound(void){
  cout<<"animal makes sound"<< endl;
  
}

void Dog::makessound(void){
  cout<<"dog barks"<<endl;
}

void Cat::makessound(void){
  cout << "meow" << endl;
}

void sound(animal* ptr){
  ptr->makessound();
}


int main(){
  animal* d = new Dog();
  d->makessound();
  sound(d);
  
  animal* aptr= new animal();
  aptr->makessound();
  sound(aptr);
  
  animal* c = new Cat();
  c->makessound();
  sound(c);

  return 0;
  
}
