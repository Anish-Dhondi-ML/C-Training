#include<iostream>
using namespace std;

int main(){

int rats = 101;
int & rodents = rats; // rodents is a reference
cout << "rats = " << rats<<endl;
cout << "rodents = " << rodents << endl;

cout << "rats address = " << &rats<<endl;
cout << "rodents address = " << &rodents << endl;

int bunnies = 50;
rodents = bunnies; // can we change the reference?

cout << "bunnies = " << bunnies<<endl;
cout << "rats = " << rats<<endl;

cout << "rodents = " << rodents << endl;
cout << "bunnies address = " << &bunnies<<endl;
cout << "rodents address = " << &rodents << endl;

return 0;
}