// The assignment program in C++ training on 01/03/2023
// This program to practice class
#include<iostream>
#include<cstring>

// note try to put the public part first and then private and protected
class Time{
    private: 
        int min; 
        int hrs;
    public:
        //Time(){min=0; hrs=0;};
        Time(int h=0, int m=0){ min=m;hrs=h;};
        void addmin(int m);
        void addhrs(int h);
        void show();
        Time totalsum(const Time &t);
        Time operator +(const Time &t);
        bool operator ==(const Time &t);
        friend std::ostream& operator <<(std::ostream &out, const Time &t);
        friend std::istream& operator >>(std::istream &in, Time &t);
        Time operator -(const Time &t);
        void operator =(const Time &t);
        
};

void Time::addmin(int min){
    this->min += min;
    this->hrs += this->min/60;
    this->min = this->min%60;
}
void Time::addhrs(int hrs){
    this->hrs += hrs;
}

void Time::show(){
    std::cout<<"Hours :"<<this->hrs<<std::endl;
    std::cout<<"Minutes :"<<this->min<<std::endl;
}
Time Time::totalsum(const Time &t){
    Time temp;
    temp.min=this->min + t.min;
    temp.hrs = temp.min/60;
    temp.min = temp.min%60;
    temp.hrs =this->hrs+t.hrs+ temp.hrs;
    return temp;
}

Time Time::operator +(const Time &t){
    Time temp;
    temp.min=this->min + t.min;
    temp.hrs = temp.min/60;
    temp.min = temp.min%60;
    temp.hrs =this->hrs+t.hrs+ temp.hrs;
    return temp;
}

bool Time:: operator ==(const Time &t){
    if(this->min==t.min && this->hrs==t.hrs)
        return true;
    else
        return false;
}
std::ostream& operator <<(std::ostream &out, const Time &t){
   out<<t.hrs<<" Hrs ";
   out<<t.min<<" mins \n";
   return out;
}

std::istream& operator >>(std::istream &in, Time &t){
    std::cout<<"Enter Hours: ";
    in>>t.hrs;
    std::cout<<"Enter Minutes: ";
    in>>t.min;
    return in;
}

Time Time::operator -(const Time &t){
    Time temp={0,0};
    
    if(this->min>=t.min)
        temp.min=this->min - t.min;
    else{
        temp.hrs =-1;
        temp.min = t.min-this->min;
    }
    temp.hrs = temp.hrs + this->hrs - t.hrs;
    return temp;
    
}
void Time::operator =(const Time &t){
    this->min=t.min;
    this->hrs=t.hrs;
}

int main(){
    Time t,t1,t2,t3;
    std::cin>>t>>t1;
    std::cout<<t<<t1;
    if(t1==t)
        std::cout<<"Time matched\n";
    else
        std::cout<<"Time not matched\n";
    t2 = t.totalsum(t1);
    t3 = t+t1+t2;
    t3=t-t1;
    std::cout<<t3;    
}