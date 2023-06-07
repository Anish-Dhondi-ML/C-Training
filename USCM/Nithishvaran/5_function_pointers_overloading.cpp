#include <iostream>
using namespace std;

void estimate(int lines, double (*estimate)(int)) {
    cout<<lines <<" of code will take "<<(*estimate)(6)<<endl;
}

double Anandestimate(int code){
    return 5.678;
}

double Ramestimate(int code){
    return 6.758;
}

int main() {
    
    int lines = 1;
    cout<<"How many lines of code"<<endl;
    cin>>lines;
    cout<<"This is Anands estimate: "<<endl;
    estimate(lines,Anandestimate);
    cout<<"This is Ram estimate: "<<endl;
    estimate(lines,Ramestimate);
    return 0;
}
