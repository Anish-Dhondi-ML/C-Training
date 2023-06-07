// The assignment program in C++ training on 06/03/2023
// This program to practice class
#include<iostream>
#include<cstring>

// note try to put the public part first and then private and protected
class StringBad{
    public:
        StringBad(const char* str);
        StringBad();
        StringBad(const StringBad &t);
        ~StringBad();
        friend std::ostream& operator <<(std::ostream &os, const StringBad &st );
        StringBad& operator =(const StringBad &st);

    private: 
        char* str;
        int len;
        static int num_string;       
};
// initializing static class member
int StringBad::num_string = 0;

StringBad::StringBad(){             // default constructor
    len = 4;
    str = new char[4];
    std::strcpy(str, "C++");        // default string
    num_string++;
    std::cout<< num_string<< ": \""<<str<<"\" default object created\n"; // FYI 
} 


StringBad::StringBad(const char * s){
    len = std::strlen(s);             // set size
    str = new char[len + 1];          // allot storage
    std::strcpy(str, s);              // initialize pointer
    num_string++;                    // set object count
    std::cout << num_string << ": \"" << str<< "\" object created\n";    // For Your Information
}
StringBad::StringBad(const StringBad &t){     //Copy Constructor
    this->len=t.len;                          //same length
    this->str= new char[len+1];               //allot space
    std::strcpy(this->str,t.str);             //copy string
    num_string++;                             // update static count
    std::cout << num_string << ": \"" << str<< "\" object created\n"; 
}

StringBad::~StringBad(){                    // necessary destructor
    std::cout<<"\""<< str << "\" object deleted, "; // FYI 
    --num_string;                           //required
    std::cout<<num_string <<" left\n";      // FYI
    delete [] str;                          // required 
}


std::ostream & operator << (std::ostream &os, const StringBad &st){
  os<<st.str;
  return os;  
} 

StringBad& StringBad:: operator = (const StringBad &st){
    delete [] this->str;
    this->len=st.len;
    this->str = new char[this->len+1];
    std::strcpy(this->str,st.str);

    return *this;
}

 
void callme1(StringBad &);  // pass by reference
void callme2(StringBad);    // pass by value
using std::cout;
int main(){
   using std::endl;
   {
        cout<< "Starting an inner block.\n";
        StringBad headline1("Celery Stalks at Midnight");
        StringBad headline2("Lettuce Prey");
        StringBad sports("Spinach Leaves Bowl for Dollars");
        cout << "headline1: " << headline1 << endl;
        cout << "headline2: " << headline2 << endl;
        cout << "sports: " << sports << endl;
        callme1(headline1);
        cout << "headline1: " << headline1 << endl;
        callme2(headline2);
        cout << "headline2: " << headline2 << endl;
        cout << "Initialize one object to another:\n";
        StringBad sailor = sports;
        cout << "sailor: " << sailor << endl;
        cout << "Assign one object to another:\n";
        StringBad knot;
        knot = headline1;
        cout << "knot: " << knot << endl;
        cout << "Exiting the block.\n";
    }
    cout << "End of main()\n";
    return 0;
}
void callme1(StringBad & rsb){
    std::cout << "String passed by reference:\n";
    std::cout << "    \"" << rsb << "\"\n";
    }
void callme2(StringBad sb){
    std::cout << "String passed by value:\n";
    std::cout << "    \"" << sb << "\"\n";
}