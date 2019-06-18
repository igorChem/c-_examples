// ochr.cpp 
// file output with characters 
#include <fstream> 
#include <iostream>
#include <string> 
using namespace std; 

int main()
{
	string str = "Time os  great teacher. but unfortunaely "
				 "it kills all its pupils. Berlioz";
	
	ofstream outfile("test.txt"); 
	
	for(int i=0; i<str.size();i++)
		outfile.put(str[i]); // for eache character write it to file
	
	cout << "File Written \n";
	
	return 0;

}
