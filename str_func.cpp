//str_func.cpp
// string functions

#include <iostream>
#include <string>
using namespace std;

int main()
{

  string firstName,lastName,nickName, fullName;
  cout << "Please could you enter your FIRST name" <<endl;
  cin >> firstName;
  cout << "Please could you enter your LAST name" <<endl;
  cin >> lastName;
  cout << "Please could you enter your NICK name" <<endl;
  cin >> nickName;
  fullName = firstName +' '+ lastName;

  cout << "The number of characters in " << fullName << " is " << fullName.size() << endl;
  cout << "The number of characters in " << fullName << " can also be found as " << fullName.length() << endl;


  string subString = firstName.substr(0,3);


  cout << "let's find the first 3 characters of the name "
       << firstName << " use substr "
       << subString
       << endl;

  firstName.erase(0,3); 

  cout << "After erasing the first 3 characters it has becomeg " 
       << firstName 
       << endl;


  firstName.insert(0,subString);   
  cout << "To re-insert those ffirst 3 characters of the string " 
       << firstName << " use insert : " 
       << firstName
       << endl;

  cout << "Your nickname is " << nickName << endl;

  size_t positionOfFirstName = fullName.find(firstName);
  cout << "Position of first name " << firstName 
       << "Inside the full name is" << positionOfFirstName << endl;
 
  fullName.replace(positionOfFirstName,firstName.length(),"");
  fullName.insert(positionOfFirstName,nickName);

  cout << "New Full name:" << fullName << endl;
  

}
