//proc_str.cpp
// get and compare strings 

#include <iostream>
#include <string>
using namespace std;

int main()
{

  string firstString;
  string secondString;

  while (true)
    {
      cout << "Please enter string 1 (empty string to exit)" << endl;
      getline(cin,firstString);
      if (firstString == "")
	{
          cout << "You entered an empty string - so exiting" << endl;
          break;
        }
      cout << "Please enter string 2" << endl;
      getline(cin,secondString);
      if(firstString < secondString) 
      {
	cout << "First string " << firstString << " is lexicographically less than Second string " << secondString << endl;
      }
      else if(firstString > secondString) 
      {
	cout << "First string " << firstString << " is lexicographically greater than than Second string " << secondString << endl;
      }
      else 
	{
	  cout << "Strings are equal!" << endl;
	}


    }

}
