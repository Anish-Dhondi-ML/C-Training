#include <iostream>
using namespace std;
class age
{
    private:
    int h,d,c=0;
    public:
    age(int a,int b )
    {
        h=a;
        d=b;
    }
    void show()
    {
        while(h>1)
        {
            h=h/60;
            c++;
        }
        cout<<"the number of hours is"<<c;
    }
};

int main()
{
    age a(133,5);
    a.show();
}
