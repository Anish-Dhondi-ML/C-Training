 #include <iostream>
using namespace std;
/*class emp
{
    public:
    int salary=600000;
    int empid=134;
};
class details:public emp
{
    public:
    int bonus=50000;
};
class performance:public details
{
    public:
    int rating=5;
};
int main()
{
    details b;
    performance p;
    cout<<b.salary<<endl;
    cout<<b.bonus<<endl<<b.empid<<endl;
    cout<<p.rating;
}*/
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
int main()
{
    dog *d=new dog();
    animal *a=new animal();
    a->make_sound();
    d->make_sound();
}
