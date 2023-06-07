#include<iostream>
#include<string>

class Stock
{

public:
    Stock(std::string c , int sher , double s_price ) : company(c) , shares(sher),share_price(s_price), total_price(sher*s_price){show_total();}
    void buy(int sher){ shares = shares + sher; total_price = shares * share_price; show_total();}
    void sell(int sher){ shares = shares - sher; total_price = shares * share_price; show_total();}
    void show_total(){
        std::cout<<"Company : "<<company<<"\n"<<"Total Shares : "<<shares<<"\n"<<"Share Price : "<<share_price<<"\n"<<"Total Price : "<<total_price<<"\n";
    }

private:
    std::string company;
    int shares;
    double share_price;
    double total_price;



};


int main()
{   
    Stock anish = {"ANISHL",5,4.25};
    Stock aakash = {"AAKASHL", 6 , 12.235};
    
    
    anish.buy(2);
    
    anish.sell(4);
    
    
    aakash.buy(9);
    
    aakash.sell(3);
    int z = 0;
    std::cout<<++z;

}