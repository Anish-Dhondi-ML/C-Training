// Session 1
// 14-02-23
// Print the area and perimeter of given shapes.



#include<iostream>
#include<string>
using namespace std;

int main()
{   
    string shape;
    cout << "Enter the shape of the object :" << endl;
    cin >> shape;
	int i;
    cout << "Enter "<<endl<<"1 : Perimeter" << endl<<"2 : Area"<<endl;
    cin >>i;

  
    float sum = 0.0;

	if (i == 1) 
    {
        
        if (shape =="square")
        {
            int s;
            cout << "Enter side length of square to find perimeter : " << endl;
            cin >> s;
            sum = 4*s;
            cout << "The perimeter of square is " << sum <<" units"<< endl;
        }

        else if (shape == "rectangle")
			{   
                int l , b;
                cout << "Enter the length of rectangle to find the perimeter : " << endl;
                cin >> l;
                cout << "Enter the breadth of rectangle to find the perimeter : " << endl;
                cin >> b;
                sum = 2*(l+b);
                cout << "The perimeter of rectangle is " << sum <<" units"<< endl;

            }

        else if (shape == "triangle")
				{   
                    int p , q, r;
                    cout << "Enter value of side1 " << endl;
                    cin >> p;
                    cout << "Enter value of side2 " << endl;
                    cin >> q;
                    cout << "Enter value of side3 " << endl;
                    cin >> r;
                    sum = p+q+r;
                    cout << "The perimeter of triangle is " << sum <<" units"<< endl;

                }

        else
            cout << "Invalid Input ";
	}
    else if(i == 2)
    {
        
        if (shape =="square")
        {
            int s;
            cout << "Enter side length of square to find area : " << endl;
            cin >> s;
            sum = s*s;
            cout << "The area of square is " << sum <<" units sq"<< endl;
        }
        

        else if (shape == "rectangle")
        {
            int l , b;
                cout << "Enter the length of rectangle to find the area : " << endl;
                cin >> l;
                cout << "Enter the breadth of rectangle to find the area : " << endl;
                cin >> b;
                sum = l*b;
                cout << "The area of rectangle is " << sum <<" units sq"<< endl;

        }

        else if (shape == "triangle")
        {
             int h, b;
                    cout << "Enter the height : " << endl;
                    cin >> h;
                    cout << "Enter the base " << endl;
                    cin >> b;
                    sum = (h+b)/2;
                    cout << "The area of triangle is " << sum <<" units sq"<< endl;

        }
         else
            cout << "Invalid Input ";

    }
}
