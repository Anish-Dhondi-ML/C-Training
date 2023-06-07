#include <iostream>
using namespace std;
class age
{
    private:
    int h,d,c=0;
    public:
    int sum;
    age(int a,int b )
    {
        h=a;
        d=b;
    }
    age()
    {
        h=0;
        d=0;
    }
    void show()
    {
        while(h>1)
        {
            h=h/60;
            c++;
        }
        cout<<"The number of hours is: "<<c<<endl<<this->d<<endl;
    }
};
int main()
{
    age a(133,5);
    age a2(133,7);
    a.show();
    a2.show();
}
