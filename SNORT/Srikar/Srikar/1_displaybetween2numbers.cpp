#include <iostream>
using namespace std;
int main()
{

    int a,b;
    cout<<"Enter the limits:"<<endl;
    cin>>a>>b;
    int i = a + 1;
    /*
    while (i < b)
    {
        cout << i << endl;
        i++;
    }
    */

    /*
    do
    {

        cout << i << endl;
        i++;
    } while (i < b);
    */
    for (int i = a + 1; i < b; i++)
    {
        cout << i << endl;
    }
}
