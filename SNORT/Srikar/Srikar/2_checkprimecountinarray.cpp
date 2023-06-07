#include <iostream>
using namespace std;
int main()
{
    int a[] = {6, 4, 2, 8, 3, 5, 11, 20};
    int n = sizeof(a) / sizeof(int);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0)
        {
            count += 1;
        }
    }
    cout<<count;
}