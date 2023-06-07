// Session 2
// 14-02-23
// Print the string text as an integer number.



#include<iostream>
#include<string>
using namespace std;

int main()
{
	cout << "Please enter an integer as a text string: ";
	string s;

	while (std::cin>>s) 
    {
		
        if (s =="zero")
				cout << s << " has the value = 0" << endl;
		
        else if (s =="one")
				cout << s << " has the value = 1" << endl;
		
        else if (s =="two")
				cout << s << " has the value = 2" << endl;
		
        else if (s =="three")
				cout << s << " has the value = 3" << endl;
		
        else if (s =="four")
				cout << s << " has the value = 4" << endl;
		
        else
				cout << s << " does not have a numeric value " << endl;
		
        cout << "Please enter another integer as a text string: ";
	}
}
