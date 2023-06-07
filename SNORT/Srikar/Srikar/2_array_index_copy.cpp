#include <iostream>
using namespace std;

int main()
{
    int n = 0;
    cout << "count of Elements is: " << endl;
    cin >> n;
    int a[n];
    int b[n];
    int i = 0;
    while (i < n)
    {
        a[i] = i;
        i++;
    }
    cout << "Elements of copied array are :" << endl;

    for (int i = 0; i < n; i++)
    {
        b[i] = a[i];
    }
    cout << "Content of original array is:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << endl;
    }
    cout << "Content of copied array is :" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << b[i] << endl;
    }

    return 0;
}