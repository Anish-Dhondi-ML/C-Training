#include <iostream>
using namespace std;

void sort(int arr[], int n)
{
    int n = sizeof(arr) / sizeof(int);
    int right = n - 1;
    int left = 0;
    while (right > left)
    {
        int i = 0;
        while (i < right - 1)
        {

            if (arr[i] > arr[i + 1])
            {
                int k = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = k;
            }
            i++;
        }
        right--;
    }
}

int main()
{
    int a[] = {2, 1, 4, 3, 6, 5};
    int size_a = sizeof(a) / sizeof(int);
    sort(a, size_a);
    for (int i = 0; i < size_a; i++)
    {
        cout << a[i] << endl;
    }
}