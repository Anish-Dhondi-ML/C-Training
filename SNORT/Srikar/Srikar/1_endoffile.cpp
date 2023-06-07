#include <iostream>
using namespace std;
int main()
{
    int i;
    int sum = 0;

    while (cin >> i)
    {
        cout << "Entered integer is: " << i << endl;
        sum = sum + i;
        cout << "cumilative sum is:" << sum << endl;
    }
    cout<<"Total sum: "<<sum<<endl;
    cout << "Terminated" << endl;
    return 0;
}
