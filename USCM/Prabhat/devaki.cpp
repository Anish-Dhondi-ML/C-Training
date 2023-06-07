#include <iostream>
#include <cctype> // for islower function
using namespace std;

// A function to check if a string is easy (all lowercase) or not
bool isEasy(string s) {
  // Loop through each character of the string
  for (char c : s) {
    // If the character is not lowercase, return false
    if (!islower(c)) {
      return false;
    }
  }
  // If all characters are lowercase, return true
  return true;
}

// A main function to test the program
int main() {
  // Declare a string variable and input it from user
  string str;
  cout << "Enter a string: ";
  cin >> str;
  
   // Call isEasy function and print its result 
  // cout << "The string is ";
   if (isEasy(str)) {
     cout << "YES" << endl;
   }
   else {
     cout << "NO" << endl;
   }
   return 0;
}