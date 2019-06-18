// finiter.cpp
// demonstrates istream_iterator with files
#include <iostream>
#include <list>
#include <fstream>
#include <algorithm>
#include <iterator>
using namespace std;

int main() {
	
	list<int> ilist;
	ifstream infile("ITER.DAT");
	
	istream_iterator<int> file_iter(infile);
	istream_iterator<int> end_of_stream;
	
	copy(file_iter,end_of_stream,back_inserter(ilist) );
	
	cout << endl;
	ostream_iterator<int> ositer(cout, "--");
	copy(ilist.begin(),ilist.end(),ositer);
	cout << endl;
	return 0;	
	
}
