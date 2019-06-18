//get_line.cpp 
// getline function, store user input in string
#include <iostream>
#include <string>
using namespace std;

int main()
{

  string firstName,lastName, fullName;
  cout << "Please could you enter your FIRST name" << endl;
  cin >> firstName;
  cout << "Please could you enter your LAST name" <<endl;
  cin >> lastName;

  fullName = firstName + lastName;

  string userInput;
  cout << "Please enter your address" << endl;
  cout << "(Press ~ when done)" << endl;
  getline(cin,userInput, '~');    //reads multiple lines
  
  cout << "First name = " << firstName << endl;
  cout << "Last name = " << lastName << endl;
  cout << "Full name = " << fullName << endl;
  cout << "Address:" << endl;
  cout << userInput << endl;

}
