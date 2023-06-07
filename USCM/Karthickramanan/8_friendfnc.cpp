#include <iostream>

using namespace std;
class abc
{
    private:
    int a;
    public:
    abc(int x)
    {
        a=x;
    }
    friend void myFriendFunction(abc obj)
    {
        cout<<obj.a;
    }
};
int main()
{
    abc obj(5);
    myFriendFunction(obj);
    return 0;
}
