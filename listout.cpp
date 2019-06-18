// listout.cpp
// iterator and for loop for output
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main() {

	int arr[] = {2,3,6,8};
	list<int> theList;
	
	for(int i = 0;i < 4;i++)
		theList.push_back( arr[i] );
		
	list<int>::iterator iter; // iterator to list of ints
	
	for(iter = theList.begin();
		iter !=theList.end();
		iter++) 
		cout << *iter << ' ';
	
	cout << endl;
	return 0;	
}
