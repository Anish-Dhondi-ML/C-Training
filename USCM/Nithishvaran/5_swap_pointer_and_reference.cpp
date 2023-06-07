#include <iostream>
using namespace std;

void swapr(int & k,int & j){
    int temp = k;
    k = j;
    j = temp;
}

void swapp(int * k,int * j){
    int temp = *k;
    *k = *j;
    *j = temp;
}

int main()
{
    // int k = 5, j = 10, temp;
    // int &it1 = k,&it2 = j;
    // swapr(it1,it2);
   
    int k = 5, j = 10, temp;
    int * it1 = &k, *it2 = &j;

    swapp(it1,it2);

    cout << "\nAfter swapping." << endl;
    cout << "k = " << k << ", j = " << j << endl;

    return 0;
}