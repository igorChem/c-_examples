// find.cpp 
// finds the first object with a specified value 
#include <iostream> 
#include <algorithm>
using namespace std; 

int arr[] = {11,22,33,44,55,66,77,88};

int main(){
	
	int* ptr;
	ptr = find(arr,arr+8,55); // find first 33 // arg1: inicio do array arg2: fim do array // valor do array para achar
	cout << "First object with value 55 found at offset "
		 << (ptr-arr) << endl;	
	
	return 0;
}
