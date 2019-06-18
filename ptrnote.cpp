// ptrnote.cpp
// array accessed with pointer notation
#include <iostream>
using namespace std;


int main() 
{
	int array[5] = {3,5,12,15,34};
	
	for(int i = 0; i<5; i++)
		cout << *(array+i) << endl; // tem que fechar os parenteses
	return 0;
	
}
