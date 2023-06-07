#include <iostream>
#include <map>
using namespace std;

int main()
{

map<std::string, int> map;

map["zero"] = 0;
map["one"] = 1;
map["two"] = 2;
map["three"] = 3;
map["four"] = 4;

string s;
cout<<"Enter the string: "<<endl;
cin>>s;

if(map[s] == 0 && s == "zero"){
    cout<<map[s];
}
else if(map[s] == 0){
    cout<<"Enteres an invalid Statement"<<endl;
}else{
    cout<<"Enter number is "<<map[s]<<endl;
}

return 0;
}
