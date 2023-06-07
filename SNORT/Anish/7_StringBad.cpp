#include<iostream>
#include<cstring>



class StringBad{

    private :
        char* str;
        int len;
        static int num_strings = 0;
        
    
    public :
        StringBad( const char * str);
        StringBad();
        ~StringBad();

        friend std::ostream& operator << (std::ostream & os,const StringBad & st);


        
};
void callme1(StringBad &); // pass by reference
void callme2(StringBad); // pass by value
int main()
{

std::cout << "Starting an inner block.\n";
StringBad headline1("Celery Stalks at Midnight");
StringBad headline2("Lettuce Prey");
StringBad sports("Spinach Leaves Bowl for Dollars");
std::cout << "headline1: " << headline1 << std::endl;
std::cout << "headline2: " << headline2 << std::endl;
std::cout << "sports: " << sports << std::endl;
callme1(headline1);
std::cout << "headline1: " << headline1 << std::endl;
callme2(headline2);
std::cout << "headline2: " << headline2 << std::endl;
std::cout << "Initialize one object to another:\n";
StringBad sailor = sports;
std::cout << "sailor: " << sailor << std::endl;
std::cout << "Assign one object to another:\n";
StringBad knot;
knot = headline1;
std::cout << "knot: " << knot << std::endl;
std::cout << "Exiting the block.\n";

std::cout << "End of main()\n";
return 0;
}
void callme1(StringBad & rsb)
{
std::cout << "String passed by reference:\n";
std::cout << " \"" << rsb << "\"\n";
}
void callme2(StringBad sb)
{
std::cout << "String passed by value:\n";
std::cout << " \"" << sb << "\"\n";
}
StringBad::StringBad(const char * s)
{
len = std::strlen(s); // set size
str = new char[len + 1]; // allot storage
std::strcpy(str, s); // initialize pointer
 // set object count
std::cout << ": \"" << str<< "\" object created\n"; // For Your Information
}
StringBad::StringBad()
{
len = 4;
str = new char [4];
// default string
std::strcpy(str, "C++"); 
std::cout << ": \"" << str<< "\" default object created\n"; // FYI
}
StringBad::~StringBad()
{
// necessary destructor
std::cout << "\"" << str << "\" object deleted, "; // FYI

// required
std::cout<< "left\n"; // FYI
delete [] str;
// required
}
std::ostream & operator<< (std::ostream & os, const StringBad & st)
{
os << st.str;
return os;
}