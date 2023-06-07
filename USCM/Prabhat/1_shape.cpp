// The assignment program in C++ training on 14/02/2023
// This program compute area and perimeter of rectangle, square and triangle

#include<iostream>

int main(){
     
    while(true){ 
        int choice=4;
        std::cout<<"\n 1. Square"<<"\n 2. Rectangle"<<"\n 3. Triangle"<<"\n 4. Exit"<<std::endl;
        std::cout<<"Enter choice: ";
        std::cin>>choice;
        if (choice==1)
        {   
            int ch=0,side=0;
            std::cout<<"Enter side in cm: ";
            std::cin>>side;
            std::cout<<"\n 1. Area"<<"\n 2. Perimeter"<<std::endl;
            std::cout<<"Enter your choice: ";
            std::cin>>ch;
            if (ch==1)
            {
                int area=side*side;
                std::cout<<"The area of the Square is "<<area<<" sq cm"<<std::endl;
            }
            else if (ch==2)
            {
                int perimeter=side*4;
                std::cout<<"The perimeter of the Square is "<<perimeter<<" cm"<<std::endl;
            }
            else if(ch!=1 && ch!=2)
                std::cout<<"Invalid choice";           
        }
        if (choice==2)
        {   
            int ch=0,length=0,breadth=0;
            std::cout<<"Enter length and breadth in cm: ";
            std::cin>>length>>breadth;
            std::cout<<"\n 1. Area"<<"\n 2. Perimeter"<<std::endl;
            std::cout<<"Enter your choice: ";
            std::cin>>ch;
            if (ch==1)
            {
                int area=length*breadth;
                std::cout<<"The area of the Rectangle is "<<area<<" sq cm"<<std::endl;
            }
            else if (ch==2)
            {
                int perimeter=2*length+2*breadth;
                std::cout<<"The perimeter of the Rectangle is "<<perimeter<<" cm"<<std::endl;
            }
            else if(ch!=1 && ch!=2)
                std::cout<<"Invalid choice";           
        }
        if (choice==3)
        {   
            int ch=0;
            std::cout<<"\n 1. Area"<<"\n 2. Perimeter"<<std::endl;
            std::cout<<"Enter your choice: ";
            std::cin>>ch;
            if (ch==1)
            {   
                int height,base;
                std::cout<<"Enter base and height in cm: ";
                std::cin>>base>>height;
                float area=height*base*0.5;
                std::cout<<"The area of the Triange is "<<area<<" sq cm"<<std::endl;
            }
            else if (ch==2)
            {   int side1=0,side2=0,side3=0;
                std::cout<<"Enter all three sides in cm: ";
                std::cin>>side1>>side2>>side3;
                int perimeter=side1+side2+side3;
                std::cout<<"The perimeter of the Triange is "<<perimeter<<" cm"<<std::endl;
            }
            else if(ch!=1 && ch!=2)
                std::cout<<"Invalid choice";           
        }
        if(choice==4)
            break;
        else
            std::cout<<"Invalid choice"<<std::endl;   
    }
}