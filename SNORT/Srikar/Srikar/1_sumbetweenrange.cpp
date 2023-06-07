#include <iostream>
using namespace std;
int main()
{

    int a = 50, b = 100, sum = 0;
    int i = a + 1;

    while (i < b)
    {
        sum += i;
        i++;
    }

    /*
    do
    {

        sum +=i;
        i++;
    } while (i < b);

   /*
    for (int i = a + 1; i < b; i++)
    {
        sum += i;
    }
    */
    cout << sum;
}