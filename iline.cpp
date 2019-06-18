//iline.cpp 
// file input with strings 
#include <fstream>
#include <iostream>
using namespace std ; 

int main()
{
	const int MAX = 80;
	char buffer[MAX];
	ifstream infile("test");
	while( !infile.eof() ) // while( infile.good ) is used to read until there is no error encoutered
	{
		infile.getline(buffer,MAX);
		cout << buffer << endl; 
	}	
	return 0;
}
