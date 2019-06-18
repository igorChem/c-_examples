//sstrcom.cpp
//comparing string objects
#include <iostream>
#include <string>
using namespace std;

int main()
{
	
	string aname = "George";
	string username;
	
	cout << "Enter your first name; ";
	cin >> username;
	
	if (username == aname)
		{ cout << "Greetings George!\n";}
		

}
