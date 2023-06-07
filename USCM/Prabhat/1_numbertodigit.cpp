// The assignment program in C++ training on 14/02/2023
// This program convert text to numeric value

#include<iostream>
#include<string>


   int main()
{
    std::string str;
	std::cout << "Enter an integer as a text string: ";
	

	while (std::cin>>str) 
    {
		
        if (str =="zero")
				std::cout << str << "  = 0" << std::endl;
		
        else if (str =="one")
				std::cout << str << "  = 1" << std::endl;
		
        else if (str =="two")
				std::cout << str << "  = 2" << std::endl;
		
        else if (str =="three")
				std::cout << str << " = 3" << std::endl;
		
        else if (str =="four")
				std::cout << str << " = 4" << std::endl;
		
        else
				std::cout << str << " It is not A numeric value" << std::endl;
		
        std::cout << "for TRY AGAIN 1\n for EXIT 2 "<<std::endl;
        int ch=0;
        if(ch==2)
            break;
	}
}