#include <iostream>
using namespace std;
int main()
{
    int i = 0;
    int sum = 0;
    while (++i <= 10)
    {
        sum = sum + i;
    }
    cout << sum;
    return 0;
    // int n=10;
    // sum = n*(n+1)/2;
    // cout<<sum;
    // return 0;
}