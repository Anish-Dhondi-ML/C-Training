#include <iostream>
using namespace std;

int main()
{
    int n = 0;
    cout << "count of Elements is: " << endl;
    cin >> n;
    int a[n];
    int i = 0;
    while (i < n)
    {
        a[i] = i;
        i++;
    }
    cout << "Elements are :" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << endl;
    }
    return 0;
}