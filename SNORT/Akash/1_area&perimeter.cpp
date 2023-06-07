#include<iostream>
#include<string>
using namespace std;
int main()
{
    string shape;
    int choice;
    cout<<"Enter the shape and choice. For choice, enter 1 to find area, 2 to find perimeter: ";
    cin>>shape>>choice;

    if(shape=="square")
    {
        int a;
        if(choice==1)
        {
            cout<<"Enter the side: ";
            cin>>a;
            int area=a*a;
            cout<<"The area of square is: "<<area;
        }
        else if(choice==2)
        {
            cout<<"Enter the side: ";
            cin>>a;
            int perimeter=4*a;
            cout<<"The perimeter of square is: "<<perimeter;
        }
        else   
            cout<<"Invalid input";
    }

    else if(shape=="rectangle")
    {
        int l,w;
        if(choice==1)
        {
            cout<<"Enter the length and width: ";
            cin>>l>>w;
            int area=l*w;
            cout<<"The area of rectangle is: "<<area;
        }
        else if(choice==2)
        {
            cout<<"Enter the length and width: ";
            cin>>l>>w;
            int perimeter=2*(l+w);
            cout<<"The perimeter of rectangle is: "<<perimeter;
        }
        else   
            cout<<"Invalid input";
    }

    else if(shape=="triangle")
    {
        int b;
        if(choice==1)
        {
            int h;
            cout<<"Enter the base and height: ";
            cin>>b>>h;
            float area=0.5*b*h;
            cout<<"The area of triangle is: "<<area;
        }
        else if(choice==2)
        {
            int a,c;
            cout<<"Enter the base and two sides: ";
            cin>>b>>a>>c;
            int perimeter=a+b+c;
            cout<<"The perimeter of triangle is: "<<perimeter;
        }
        else   
            cout<<"Invalid input";
    }

    else
        cout<<"Invalid input";
}
