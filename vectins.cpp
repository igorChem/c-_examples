// vectins.cpp
// demonstrates insert(), erase()
#include <iostream>
#include <vector>
using namespace std;

int main() { 
	
	int arr[] = { 100, 110, 120, 130 };
	
	vector<int> v(arr,arr+4);
	
	cout << "\nBefore insertion: ";
	for(int i=0; i<v.size();i++)
		cout << v[i] << "  ";
		
	v.insert(v.begin()+2,115); // insert element 115 at position 2 
	
	cout << "\nAfter insertion: "<< endl;
	for(int k = 0; k<v.size();k++)
		cout<< v[k] << "   ";
		
	v.erase( v.begin()+2 ); // erase element 2 //muito interessente essa função begin 

	cout << "\nAfter erase:  ";
	for(int j = 0; j<v.size();j++)
		cout << v[j] << "  "; 
	
	cout << endl; 
	return 0;
	
}
