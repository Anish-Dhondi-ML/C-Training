#include <iostream>
using namespace std;
void desc_sort(int arr[], int n)
{

    int i = 0;
    while (i < n)
    {
        int j = i + 1;
        while (j < n)
        {
            if (arr[i] < arr[j])
            {
                int k = arr[i];
                arr[i] = arr[j];
                arr[j] = k;
            }
            j++;
        }
        i++;
    }
}

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
    desc_sort(a, n);
    cout << "Elements in desc order :" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << endl;
    }
    return 0;
}