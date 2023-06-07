#include <iostream>
using namespace std;
class age {
private:
    int h;
    int d,c=0;
public:
    age(int a, int b) {
        h = a;
        d = b;
    }
    age() {
        h = 0;
        d = 0;
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
    age operator+(const age& other) {
        age result;
        result.d = d + other.d;
        return result;
    }
    void show1() {
       cout<<"total days"<<d;
    }
};
int main() {
    age a(133, 5);
    age a2(133, 7);
    age a3 = a + a2;
    a.show();
    a2.show();
    a3.show1();
}
