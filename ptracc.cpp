// ptracc.cpp
// accessing the variable pointed to
#include <iostream>
using namespace std;


int main()
{
	int a, b, c;
	a=11; b=22; c=33;
	
	cout << &a << endl 
		 << &b << endl 
		 << &c << endl;
		 
	int* ptr;  // pointer initialized 
	
	ptr = &a; // the pointer gets the memory adress of a variable
	cout << *ptr << endl;
	
	ptr = &b; // the pointer gets the memory adress of a variable
	cout << *ptr << endl;
	return 0;
}
