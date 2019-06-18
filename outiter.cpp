//outiter.cpp
//demonstrates ostream_iterator
#include <iostream>
#include <algorithm>
#include <list>
#include <iterator> // não esquecer de incluir essa bost aqui para usar iterators
using namespace std;

int main() { 
	
	int arr[] = { 10, 20, 30, 40, 50 };
	list<int> theList;
	
	for(int i = 0 ;i<5;i++)
		theList.push_back( arr[i] );
	
	ostream_iterator<int> ositer(cout, ", ");
	
	cout << "\nContents of List: "; 
	copy(theList.begin(),theList.end(),ositer); 
	cout << endl; 
	
	return 0;	
	}
