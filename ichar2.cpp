// ichar2.cpp 
// file input with charaters 

#include <fstream>
#include <iostream> 

using namespace std; 

int main() {
	
	ifstream infile("test.txt"); // create file fo input 
	
	cout << infile.rdbuf(); // send its buffer to cout 
	cout << endl; 
	return 0; 	
	}
