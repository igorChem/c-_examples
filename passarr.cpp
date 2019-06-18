// passarr.cpp
// array passed by pointer
#include <iostream>
using namespace std;

const int MAX = 5;

int main()
{
	void centimize(double*);
	
	double vararray[MAX] = {10.0, 43.1, 95.9,59.7, 87.3 };
	
	centimize(vararray);
	
	for(int i = 0; i<MAX;i++)
		cout << "vararray[" << i << "]= "
			 << vararray[i] << " centimeters" << endl;
			 
	return 0;
}

/////////////////////////////////////////////////////

void centimize(double* ptrd)
{
	for(int i=0;i<MAX;i++)
		*ptrd++ *=2.54;
}
