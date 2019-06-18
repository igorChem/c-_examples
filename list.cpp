//list.cpp
//demonstrates push_front(), front(), pop_front()
#include <iostream>
#include <list>
using namespace std;

int main() {

	list <int> ilist;
	
	ilist.push_back(30);
	ilist.push_back(40);
	ilist.push_front(20);
	ilist.push_front(10);
	
	int size = ilist.size();
	
	for(int i = 0; i<size ; i++){
		cout << ilist.front() << " "; // read item from front
		ilist.pop_front(); //pop item off front 
		}
	cout << endl;
	return 0;

}
