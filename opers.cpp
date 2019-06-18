// opers.cpp
// saves person object to disk
#include <fstream>
//for file streams
#include <iostream>
using namespace std;

class Person {
	protected:
		char name[80];
		short age;	
	public: 
		void get_data(){
			cout << "enter name: "; cin >> name; 
			cout << "enter age: "; cin >> age;
		}			
};

int main(){
	
	Person pers;
	pers.get_data();
	
	ofstream outfile("PERSON.DAT",ios::binary);
	
	outfile.write(reinterpret_cast<char*>(&pers),sizeof(pers));
	return 0;	
	}
