#include <iostream>

using namespace std;

int main()
{

int x=0,y=0,z=0;

cout<<"1. Perimeter"<<endl;
cout<<"2. Area"<<endl;
int input_0;
cin>>input_0;

if(input_0 == 1){
    cout<<"1. Perimeter of Rectangle: "<<endl;
    cout<<"2. Perimeter of Square: "<<endl;
    cout<<"3. Perimeter of Triangle: "<<endl;

int input_1=0;
cin>>input_1;

    if(input_1 == 1){
        cout<<"Enter length: "<<endl;
        cin>>x;
        cout<<"Enter width: "<<endl;
        cin>>y;
        cout<<"Perimeter of the rectangle: "<<2*(x+y)<<endl;
    }
    if(input_1 == 2){
        cout<<"Enter length(a): "<<endl;
        cin>>x;
        cout<<"Perimeter of the square: "<<4*x<<endl;
    }
    if(input_1 == 3){
        cout<<"Enter side_1: "<<endl;
        cin>>x;
        cout<<"Enter side_2: "<<endl;
        cin>>y;
        cout<<"Enter side_3: "<<endl;
        cin>>z;
        cout<<"Perimeter of the Triangle: "<<(x+y+z)<<endl;
    }
}else{
   
    cout<<"1. Area of Rectangle: "<<endl;
    cout<<"2. Area of Square: "<<endl;
    cout<<"3. Area of Triangle: "<<endl;
    
    int input_2=0;
    cin>>input_2;

    if(input_2 == 1){
        cout<<"Enter length: "<<endl;
        cin>>x;
        cout<<"Enter width: "<<endl;
        cin>>y;
        cout<<"Area of the Rectangle: "<<x*y<<endl;
    }
    if(input_2 == 2){
        cout<<"Enter length: "<<endl;
        cin>>x;
        cout<<"Area of the square: "<<x*x<<endl;
    }
    if(input_2 == 3){
       cout<<"Enter base: "<<endl;
       cin>>x;
       cout<<"Enter height: "<<endl;
       cin>>y;
       cout<<"Area of the triangle: "<<(x*y)/2<<endl;
    }
}

return 0;
}
