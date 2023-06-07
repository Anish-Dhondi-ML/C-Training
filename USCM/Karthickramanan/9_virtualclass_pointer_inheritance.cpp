#include<iostream>
using namespace std;
class animal
{
    public:
    virtual void make_sound();
};
class dog:public animal
{
    public:
    virtual void make_sound();
};
void animal::make_sound(void)
{
    cout<<"animal sound"<<endl;
}
void dog::make_sound(void)
{
    cout<<"dog barks"<<endl;
}
void sound(animal *ptr)
{
    ptr->make_sound();
}
int main()
{
    animal *d=new dog();
    animal *a=new animal();
    a->make_sound();
    sound(a);
    d->make_sound();
    sound(d);
    
    
}
