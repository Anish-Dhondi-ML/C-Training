#include<iostream>

class Time
{
    public :
        Time(int m , int h) : min(m) , hr(h) {std::cout<<"HR:MIN - "<<h<<":"<<m<<std::endl;}
        void add_min(int m){
            min += m;
            hr = hr + (min/60);
            min = (min % 60);
        }
        void add_hr(int h){
            hr += h;
        }
        void show_time()
        {
            std::cout<<"HR:MIN - "<<hr<<":"<<min<<"  "<<std::endl;
        }

        Time operator + (const Time &t) const;
        Time operator = (const Time &t) const;
        friend std::ostream& operator<<(std::ostream& os, const Time& t) {
        os << t.hr << ":" << t.min << std::endl;
        return os;
    }
        

    

    private :
        int min ;
        int hr ; 
        


};

int main()
{   
    Time t2 = {22,2};
    Time t1 = {12,04};
    t2.show_time();
    t2.add_hr(0);
    t2.add_min(187);
    t2.show_time();
    t1.show_time();
    Time t3 = t1 + t2;
    std::cout<<t1;
    Time t4 = t2;
    std::cout<<t4;


}

Time Time::operator+(const Time &t) const
{   int hours = this->hr + t.hr;
    int minutes = this->min + t.min;
    if (minutes >= 60) {
        minutes -= 60;
        hours++;
    }
    Time result(minutes, hours);
    return result;
    
}

Time Time::operator=(const Time &t) const
{ 
    int hour = t.hr;
    int minute =t.min;
    Time result(minute,hour);

    return result;
}
