//sstrfind.cpp
//finding substrings in string objects
#include <iostream>
#include <string>
using namespace std;

int main()
{
	
	string s1 ="In Xanadu did Kubla Kahn a stately pleasure dome decree";
	int n;
	n = s1.find("Kubla");
	
	cout << "Found Kubla at: " << n << endl;	
	
	n = s1.find_first_of("spde");
	cout << "First of spde: " << n << endl;
		
	n = s1.find_first_not_of("AEIOUaeiou");
	cout << "First of consonate: " << n << endl;
		
	n = s1.find_first_of("AEIOUaeiou");
	cout << "First of vogal: " << n << endl;
	
	n = s1.find_first_of(" ");
	cout << "First of empty space: " << n << endl;	
	}
