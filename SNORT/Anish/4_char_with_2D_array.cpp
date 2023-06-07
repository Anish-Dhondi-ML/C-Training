int main()
{
char str[5][10]  {"Apple","Samsung","Sony","MapleLabs","Oppo"};
char (*ptr)[5][10] = &str ;  
char (*ptr1) = &str[0][10];                

     for(int i {0};i<5;i++)
        { 
        
            std::cout<<(*ptr)[i]<<std::endl;
        }

        for(int i {0};i<5;i++)
        { for (int j{0};j<10;j++){
        if((*ptr)[i][j] == '\0')
                break;
            std::cout<<(*ptr)[i][j]<<" ";
        }
        std::cout<<std::endl;
        }
// for single dimension array
char (*ptr2)[10] = str;
for(int k{0};k<5;k++){
std::cout<<*(ptr2 + k) <<std::endl;
}

      
}
