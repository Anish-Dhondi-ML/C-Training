#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    cout << "0.Triangle" << endl;
    cout << "1.rectangle" << endl;
    cout << "2.Square" << endl;

    int poly;
    cout << "Enter the choice for polygon" << endl;
    cin >> poly;
    if (poly == 0)
    {
        int ch, P, a, b, c;
        float area;
        cout << "Enter the sides of triangle" << endl;
        cin >> a >> b >> c;
        cout << "Enter the choice for metric" << endl;
        cout << "0.Perimetre" << endl;
        cout << "1.Area" << endl;
        P = a + b + c;
        area = sqrt(P / 2 * (P / 2 - a) * (P / 2 - b) * (P / 2 - c));

        cin >> ch;
        if (ch == 0)
        {
            cout << P;
        }
        if (ch == 1)
        {
            cout << area;
        }
    }
    if (poly == 1)
    {
        int ch, a, b, P, area;
        cout << "Enter the length and breadth of rectangle " << endl;
        cin >> a >> b;
        cout << "Enter the choice for metric" << endl;
        cout << "0.Perimetre" << endl;
        cout << "1.Area" << endl;
        P = 2 * (a + b);
        area = a * b;

        cin >> ch;
        if (ch == 0)
        {
            cout << P;
        }
        if (ch == 1)
        {
            cout << area;
        }
    }
    if (poly == 2)
    {
        int ch, a, P, area;
        cout << "Enter the side of square" << endl;
        cin >> a;
        cout << "Enter the choice for metric" << endl;
        cout << "0.Perimetre" << endl;
        cout << "1.Area" << endl;
        P = 4 * (a);
        area = a * a;

        cin >> ch;
        if (ch == 0)
        {
            cout << P;
        }
        if (ch == 1)
        {
            cout << area;
        }
    }
    return 0;
}