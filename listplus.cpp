// listplus.cpp
// demonstrates reverse(), merge(), and unique()
#include <iostream>
#include <list>
using namespace std;

int main() { 
	
	int j;
	list<int> list1, list2;
	
	int arr1[] = { 40, 30, 20, 10 };
	int arr2[] = { 15, 20, 25, 30, 35 };
	
	for(j = 0; j<4; j++)
		list1.push_back( arr1[j] );
	for(j = 0; j<5;j++)
		list1.push_back( arr2[j] );
	
	list1.reverse();
	list1.merge(list2);
	list1.unique(); // remove duplicates 20 and 30, isso é muito interessante
	
	int size = list1.size();
	while( !list1.empty() ) // enquanto a list1 não estiver vazia 
	{
		cout << list1.front() << "  "; //read item from front 
		list1.pop_front();
	}
	cout << endl;
	return 0;
}
