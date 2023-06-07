#include <iostream>
#include <string>
using namespace std;
 
int main()
{
    
    char str[5][10]{"Alice","Aakash","Nithish","MapleLabs"};
    char(*ptr)[5][10] = &str;
 
    for(int i=0; *(ptr+i) != NULL;i++){
        string result;
        for(int j=0; *(ptr+i+j) != NULL;j++){
          result +=*(ptr[i][j]);
        }
       if(result == "Maplelabs"){
          cout<<"The string is present"<<endl;
      }
    }
    cout<<"\n HI";
    return 0;
}