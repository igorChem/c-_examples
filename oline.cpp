//oline.cpp
// file output with strings 
#include <fstream> 
using namespace std; 

int main()
{
	ofstream outfile("test"); // create file for output
	
	outfile << "I fear thee, ancient Mariner! \n";
	outfile << "I fear thy skinny hand \n"; 
	outfile << "And thou art lon, and lank, and brown,\n";
	outfile << "As is the ribbed sea sand. \n"; 
	
	return 0;
}
