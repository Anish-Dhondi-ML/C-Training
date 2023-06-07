// Session 1
// 13-02-23
// Using While,Do-while, For loop print sum of 50 to 100


#include<iostream>
using namespace std;

int main() {

cout<<"Using While Loop :"<<endl;
int i = 50;
int sum = 0;
while(i <= 100){
    cout<<i<<endl;
    sum += i;
    i++;

}
cout<<"sum = "<<sum<<endl;

cout<<"Using Do-While Loop :"<<endl;
i = 50;
sum = 0;
do
{
   cout<<i<<endl;
    sum += i;
    i++;
} while ( i <= 100 );
cout<<"sum = "<<sum<<endl;

cout<<"Using For Loop :"<<endl;

sum = 0;
for ( i = 50; i <= 100; i++)
{
   cout<<i<<endl;
    sum += i;
}
cout<<"sum = "<<sum<<endl;



return 0 ;
}
