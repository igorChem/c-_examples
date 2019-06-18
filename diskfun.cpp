// diskfun.cpp
// reads and writes several objects to disk
#include <fstream>
//for file streams
#include <iostream>
using namespace std;
/////////////////////////////////////////////////////
class person {
	protected:
		char name[80];
		short age;
	public:
		void get_data(){
			cout << "\n Enter name: "; cin >> name; 
			cout << " Enter age: "; cin >> age;
			}
		void showData(){
			cout << "\n Name: " << name;
			cout << "\n Age: " << age;				
	}
};

int main(){
	
	char ch;
	person pers; 
	fstream file; 
	
	file.open("GROUP.DAT",ios::app | ios::in | ios::out | ios::binary); // data from user to file 
	
	do {
		cout << "\nEnter person's data";
		pers.get_data(); 
		
		file.write( reinterpret_cast<char*>(&pers),sizeof(pers) );
		cout << "Enter another person (y/n)? ";
		cin >> ch;
	}
	while(ch == 'y');
	file.seekg(0); // reset to start of file
	
	file.read( reinterpret_cast<char*>(&pers),sizeof(pers) );
	while( !file.eof() ) { // read until the endo of file 
		cout << "\nPerson: "; 
		pers.showData(); 
		file.read( reinterpret_cast<char*>(&pers),sizeof(pers) );
	}
	cout << endl; 
	return 0;
}
