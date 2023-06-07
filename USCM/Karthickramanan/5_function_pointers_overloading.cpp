#include <iostream>
using namespace std;
void price(int lines,double (*price)(int))
{
    cout<<(*price)(lines);
}
double ananthestimate(int code)
{
    return 3.22;
}
int main()
{
    int lines;
    cout<<"enter the lines";
    cin>>lines;
    price(lines,ananthestimate);
}
