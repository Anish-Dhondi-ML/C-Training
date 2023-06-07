// This is to see how to use our smart pointer
#include<iostream>
#include "10_Playptr.h"
using namespace std;
typedef struct {
    int x=2;
    int y=3;
} Point;
ostream& operator<<(ostream& os, const Point& p)
{
    os << "x: " << p.x << ", y: " << p.y;
    return os;
}


int main(){
    Point *leakptr = new Point;
    Playptr<Point> smartptr( new Point);
    cout<<smartptr->x<<endl;
    cout<<smartptr->y<<endl;
    cout<<(*leakptr)<<endl;
    cout<<(*smartptr)<<endl;

    delete leakptr;
    return 0;
}