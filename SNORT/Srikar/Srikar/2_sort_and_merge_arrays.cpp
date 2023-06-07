#include <iostream>
using namespace std;

void sort(int arr[], int n)
{
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

    int a[] = {4, 5, 2, 1, 6};
    int b[] = {11, 7, 18, 12, 10};

    int size_a = sizeof(a) / sizeof(int);
    int size_b = sizeof(b) / sizeof(int);
    int result[size_a + size_b];
    int i = 0, j = 0, k = 0;

    while (i < (size_a + size_b))
    {
        if (i < size_a)
        {
            result[i++] = a[j++];
        }
        else
        {
            result[i++] = b[k++];
        }
    }

    sort(result, (size_a + size_b));
    for (int i = 0; i < (size_a + size_b); i++)
    {
        cout << result[i] << endl;
    }
    return 0;
}