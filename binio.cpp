//binio.cpp 
//binary input and output with integers 

#include <fstream> 
#include <iostream> 
#include <string>
#include <cstring>

using namespace std; 

const int MAX = 100; 

int buff[MAX];  // buffer for integers 

int main() {

	for(int i = 0; i < MAX; i++)
		buff[i] = i; 
		
	string filename = "edata.dat";
	ofstream os(filename.c_str(),ios::binary); 
	// write the buffer object as a binary file format 
	os.write( reinterpret_cast<char*>(buff), MAX*sizeof(int));
	os.close();
	
	
	for (int i=0; i < MAX; i++) // erasing buffer 
		buff[i] = 0;
	
	ifstream is("edata.dat", ios::binary); // creating file object to read binary
	
	is.read( reinterpret_cast<char*>(buff), MAX*sizeof(int));
	
	for(int i=0;i<MAX;i++) //
		if( buff[i] != i)
			{ cerr << "Data is incorrect \n"; return 1;}
	
	cout << "Data is correct \n" ;
	return 0; 
	
	}
