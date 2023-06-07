// The assignment program in C++ training on 01/03/2023
// This program to practice class
#include<iostream>
#include<cstring>

// note try to put the public part first and then private and protected
class Stock{
    private: 
        std::string company="\0"; 
        int share=0;
        double shares_price=0;
        double total_price=0;
    public:
        bool buy (std::string, int, double);       
        bool sell (std::string, int, double);
        void showprice();
        Stock(){company="\0"; share=0; shares_price=0;};
        Stock(std::string c, int s, double sp){
            company=c;
            share=s;
            shares_price=sp;
            total_price=s*sp;
        };
        Stock(std::string c){company=c;};
};
bool Stock::buy(std::string c_name, int b_share, double b_price){
    if(company==c_name){
        share +=b_share;
        shares_price =b_price;
        total_price = total_price + b_price*b_share;
        std::cout<<"Share Bought"<<std::endl;
        return true;
    }
    else
        return false;
}

bool Stock::sell(std::string c_name, int s_share, double s_price){
    if(company==c_name){
        if(share<s_share){
            std::cout<<"You dont have enough share to old"<<std::endl;
            return false;
        }
        share -=s_share;
        shares_price = s_price;
        total_price = total_price - s_price*s_share;
        std::cout<<"Share sold"<<std::endl;
        return true;
    }
    else
        return false;
}
void Stock::showprice(){
    std::cout<<"Company name :"<<company<<std::endl;
    std::cout<<"Total share :"<<share<<std::endl;
    std::cout<<"Share Price :"<<shares_price<<std::endl;
    std::cout<<"Total share price :"<<share*shares_price<<std::endl;
}


int main(){
   Stock maple("maple");
   maple.showprice();
   maple.buy("maple",5,25);
   maple.showprice();
}