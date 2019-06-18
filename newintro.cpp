// newintro.cpp
// introduces operator new
#include <iostream>
#include <cstring>
#include <string>
 //for strlen
using namespace std;



int main()
{
	string* str = 'Idle hands are the devils workshop.';
	int len = strlen(str);
	
	char* ptr;
	ptr = new char[len+1]
	
	strcpy(ptr,str);
	
	cout << "ptr= " << ptr << endl; 
	
	delete[] ptr;
	return 0;

}
