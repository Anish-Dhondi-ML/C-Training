#include <iostream>
using namespace std;
int main()
{
    int i = 10;
    /*
        do
        {
            cout << i << endl;
        } while (--i > 0);
        */
    /**
 while (i > 0)
 {
     cout << i << endl;
     i -= 1;
 }
 */
    for (int i = 10; i >= 1; i--)
    {
        cout << i << endl;
    }

    return 0;
}