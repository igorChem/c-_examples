// ptrinc.cpp
// array accessed with pointer
#include <iostream>
using namespace std;

int main()
{
	int array[] = {3, 12, 23, 25,43};
	int* prtint; 
	
	prtint = array;
	
	for(int i= 0;i<5;i++)
		cout << *(prtint++) << endl;
		
	return 0;
	
}
