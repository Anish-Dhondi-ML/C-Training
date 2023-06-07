// Session 2
// 14-02-23
// Print the area and perimeter of a required shape.



#include<iostream>
#include<string>
using namespace std;

int main()
{
	int i;
  cout << "Please enter 1 to find the perimeter or 2 to find the area of different shapes : " << endl;
  cin >> i;
  
  string s;
  float sum = 0.0;

	if (i == 1) 
    {
        cout << "Enter a shape " << endl;
        cin >> s;
		
       
        if (s =="square")
        {
            int a;
            cout << "Enter a value to find the perimeter : " << endl;
            cin >> a;
            sum = 4*a;

            cout << "The perimeter of square is " << sum << endl;

        }
		
        else if (s == "rectangle")
			{   
                int l , w;
                cout << "Enter the length to find the perimeter : " << endl;
                cin >> l;
                cout << "Enter the width to find the perimeter : " << endl;
                cin >> w;

                sum = 2*(l+w);

                cout << "The perimeter of rectangle is " << sum << endl;

            }
		
        else if (s == "triangle")
				{   
                    int x , y, z;
                    cout << "Enter value1 " << endl;
                    cin >> x;
                    cout << "Enter value2 " << endl;
                    cin >> y;
                    cout << "Enter value3 " << endl;
                    cin >> z;

                    sum = x+y+z;

                    cout << "The perimeter of triangle is " << sum << endl;

                }
		
        else
            cout << "Invalid Input ";
	}
    else if(i == 2)
    {
        cout << "Enter a shape " << endl;
        cin >> s;

        if (s =="square")
        {
            int a;
            cout << "Enter a value to find the area : " << endl;
            cin >> a;
            sum = a*a;

            cout << "The area of square is " << sum << endl;
        }
        
        else if (s == "rectangle")
        {
            int l , w;
                cout << "Enter the length to find the area : " << endl;
                cin >> l;
                cout << "Enter the width to find the area : " << endl;
                cin >> w;

                sum = l*w;

                cout << "The area of rectangle is " << sum << endl;

        }

        else if (s == "triangle")
        {
             int h, b;
                    cout << "Enter the height : " << endl;
                    cin >> h;
                    cout << "Enter the base " << endl;
                    cin >> b;

                    sum = (h+b)/2;

                    cout << "The perimeter of triangle is " << sum << endl;

        }

         else
            cout << "Invalid Input ";

    }
}
