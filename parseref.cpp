// parseref.cpp
// arguments passed as reference to a function
#include <iostream> 
using namespace std;

int main()
{
	
	void centimize(double&);
	
	double var = 10.0;
	
	centimize(var);
	cout << "var = " << var << " centimeters" << endl;
	
	return 0;	
	
}
/////////////////////////////////////////////////////

void centimize(double& v)
{	
	v *=2.54;
}
