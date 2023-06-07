#include <iostream>
using namespace std;

const int a=0;
const int b=1; 
int addition(int a,int b) {
    return a + b;
}

int subtract(int a,int b) {
    return a - b;
}

int main() {
    int (*operations[2])(int,int) = {addition, subtract};
    cout<<operations[0](2,3);
    return 0;
}