#include <iostream>
using namespace std;
int main()
{
    int a[] = {5, 6, 8, 10, 2};
    int k;
    int size_a = sizeof(a) / sizeof(int);
    int left = 0;
    int right = size_a - 1;
    while (left < right)
    {
        k = a[left];
        a[left] = a[right];
        a[right] = k;
        left++;
        right--;
    }
    for (int i = 0; i < size_a; i++)
    {
        cout << a[i] << endl;
    }
}