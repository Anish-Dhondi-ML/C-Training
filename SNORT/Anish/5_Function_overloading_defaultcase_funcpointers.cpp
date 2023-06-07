#include<iostream>

void func();
void func(int x ,int y = 10 )
{
    std::cout<<x+y<<std::endl;
}

void sort_desc(int *ip,int s2)
{   int i {0};
    while(i <s2){
    std::cout<<*(ip+i)<<" ";
    i++;
}
std::cout<<std::endl;
}

int main()
{
int a =2;
int b = 3;
int ar[10] {1,2,3,4,45,71,41,28,89,65};
int *ip = &ar[0];
sort_desc(ip,sizeof(ar)/sizeof(ar[0]));

func();
func(a,b);
func(a);

}
void func(){
    std::cout<<"hello"<<std::endl;
    
}
