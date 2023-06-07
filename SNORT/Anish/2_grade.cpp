// The assignment program in C++ training on 15/02/2023
// This program to assign grades to the student
#include<iostream>

int main(){
    int grade[12]{0,0,0,0,0,0,0,0,0,0,0,0};
    bool control=true;
    do{
        int choice;
        std::cout<<"\n 1.Enter marks out of 100";
        std::cout<<"\n 2. See grade"<<"\n 3. Exit";
        std::cout<<"\n select your choice :";
        std::cin>>choice;
        
        if(choice==1){
            int n;
            std::cout<<"How many entries you want to do : ";
            std::cin>>n;

            for(int i{0}; i<n; i++){
                int marks{-1};
                std::cout<<"\n Enter marks :";
                std::cin>>marks;
                if(marks>=0 && marks<=100){
                    if (marks==0)
                        grade[0]++;
                    else if(marks<=9)
                        grade[1]++;
                    else if(marks<=19)
                        grade[2]++;
                    else if(marks<=29)
                        grade[3]++;
                    else if(marks<=39)
                        grade[4]++;
                    else if(marks<=49)
                        grade[5]++;
                    else if(marks<=59)
                        grade[6]++;
                    else if(marks<=69)
                        grade[7]++;
                    else if(marks<=79)
                        grade[8]++;
                    else if(marks<=89)
                        grade[9]++;
                    else if(marks<=99)
                        grade[10]++;
                    else if(marks==100)
                        grade[11]++;                                       
                }
               
            }
        }
        else if (choice==2){
            std::cout<<"grade 0 : "<<grade[0]<<std::endl;
            std::cout<<"grade 1-9 : "<<grade[1]<<std::endl;
            std::cout<<"grade 10-19 : "<<grade[2]<<std::endl;
            std::cout<<"grade 20-29 : "<<grade[3]<<std::endl;
            std::cout<<"grade 30-39 : "<<grade[4]<<std::endl;
            std::cout<<"grade 40-49 : "<<grade[5]<<std::endl;
            std::cout<<"grade 50-59 : "<<grade[6]<<std::endl;
            std::cout<<"grade 60-69 : "<<grade[7]<<std::endl;
            std::cout<<"grade 70-79 : "<<grade[8]<<std::endl;
            std::cout<<"grade 80-89 : "<<grade[9]<<std::endl;
            std::cout<<"grade 90-99 : "<<grade[10]<<std::endl;
            std::cout<<"grade 100 : "<<grade[11]<<std::endl;
            }
        else if(choice ==3)
            control=false;
        else
            std::cout<<"\n Wrong choice.....\n";
        
    }while(control);
} 