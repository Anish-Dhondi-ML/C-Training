#include<iostream>

class Animal{
    public:
        virtual void makes_sound();
        virtual void has_legs();
};

class Dog : public Animal{
    public:
        virtual void makes_sound();
        virtual void baby();
        virtual void has_legs();
};




int main(){

    Animal* a = new Animal; 
    a->makes_sound(); 
    a->has_legs();
    a = new Dog; 
    a->makes_sound(); 
    Dog* d = new Dog;
    d->makes_sound();
    a->has_legs();
    d->has_legs();
    d->baby();

    delete a;
    delete d; 
     
}
void Dog :: makes_sound(){
    std::cout<<"They Bark..."<<std::endl;
}

void Dog :: baby()
{
    std::cout<<"Hello Puppy..."<<std::endl;
}

void Animal :: makes_sound(){
    std::cout<<"They Make some Sound..."<<std::endl;
}

void Animal::has_legs()
{
    std::cout<<"Depends on animal..."<<std::endl;
}
void Dog::has_legs()
{
    std::cout<<"Dog has 4 Legs..."<<std::endl;
}

