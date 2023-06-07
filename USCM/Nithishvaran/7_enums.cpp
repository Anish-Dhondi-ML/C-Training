#include <iostream>
using namespace std;

// enum and anum class are different in the way they have used 

int main()
{
    enum class Month 
    {
        Jan, 
        Feb,
        March
    };
 
    enum class Week
    {
        Sunday,
        Monday,
        Tuesday
    };
 
    Month month=Month::Jan;
	
    Week week=Week::Monday;
	
    if (month==Month::Jan) 
    	cout << "Month and Week are same\n";
    else
        cout << "Month and Week are not same\n";
    return 0;
}