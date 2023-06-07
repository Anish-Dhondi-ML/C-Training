//Session 2
//16-02-2023
//Check if the given number is a prime number or not.



#include <iostream>

int checkingPrm(int num){
    if (num <= 1)
      { 
        return 0; 
      }
   
   for (int j = 2; j <= num/2; j++)
   {
      if (num % j == 0)
      {
         return 0;
      }
      return 1;
   }
}


int main()
{
   int arr[] = { 1,3,5,4,8,13,11,20,234,24352,467654,6573,97 };
   int n = 12;
   int count=0;
   int prime=0;
   
   for(int i=0;i<n;i++)
   {
      prime=checkingPrm(arr[i]);
      if(prime==1)
      {
        count++;
      }
    
   }

   std::cout<<"Number of primes in array : "<<count << std::endl;
}
