#include <iostream>
#include <string>
using namespace std;

int main()
{
  
    char str[5][10]{"Alice","Aakash","Nithish","MapleLabs","Bob"};
    char (*ptr)[5][10] = &str;
    string abc;
   
    // for(int i=0;i < 5;i++){
    //     abc = *(*(ptr)+i);
    //     if(abc == "MapleLabs"){
    //         cout<<"The string is Present"<<endl;
    //     }
    // }

    for(int i=0;i<5;i++){
        abc = "";
        for(int j=0;(*ptr)[i][j] != '\0';j++){
            abc += (*ptr)[i][j];
        }
        if(abc == "MapleLabs"){
            cout<<"The string is present";
            break;
        }
    }

    return 0;
}

