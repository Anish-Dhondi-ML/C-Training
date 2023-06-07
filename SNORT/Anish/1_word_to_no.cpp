// Session 1
// 14-02-23
// text string to integer detection and display



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
				std::cout << str << " It does not hold any numeric value" << std::endl;
		
        std::cout << "Try with other text string: ";
	}
}