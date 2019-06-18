// sstrio.cpp
// string class input/output
#include <iostream>
#include <string>  //for string class
using namespace std;

int main ()
{
	string fullname, nickname, adress;	
	string gretting("Hello ");
	
	cout << "Enter your full name: " << endl; 
	getline(cin,fullname);
	cout << "Your full name is " << fullname << endl;
	
	cout << "Enter your nickname: " << endl; 
	cin >> nickname;
	cout << "Your nickname is " << nickname << endl; 	
	
	cout << "Enter your address on separate lines\n";
	cout << "Terminate with ‘$’\n";
	getline(cin, address, '$'); 	//reads multiple lines
	cout << "Your address is: " << address << endl;
	return 0;
}


