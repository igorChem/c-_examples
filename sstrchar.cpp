//sstrchar.cpp
//accessing characters in string objects
#include <iostream>
#include <string>
using namespace std;


int main()
{
	string chararray[80];
	string word;

	cout << "Enter a word: " << endl;
	cin >> word; 
	int wlen = word.length();
	
	
	for (int i=0;i<wlen;i++)
	 cout << word.at(i);
	

}
