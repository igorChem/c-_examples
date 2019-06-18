// sort.cpp 
// sorts an array of integers 
#include <iostream> 
#include <algorithm>

using namespace std;

int arr[] = {45,2,22,-17,0,-30,35,55};

int main() { 

	sort(arr,arr+8);
	
	for(int i = 0; i<8; i++) 
		cout << arr[i] << ' ';
	cout << endl; 
	return 0;
	
}
